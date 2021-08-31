/// <summary>
/// BOJ 21608 상어초등학교
/// 알고리즘: 구현, 수학
/// 
/// 학생 번호, 교실 칸은 1부터 시작
/// 교실 칸 : board[][] = 0 초기화
/// board[i][j] = 0 -- > empty
/// 
/// 자리 배정 : N ^ 2 * N * N * 4
/// 만족도 계산 : N ^ 2
/// </summary>

#include <iostream>

using namespace std;

struct Student {
	int likes[4] = { 0, }; // 좋아하는 학생 번호 
	int row = 0, col = 0; // 학생이 배정된 칸
};

const int MAX_N = 21;
const int MAX_ST = 410; // N^2

// 상하좌우 인접 칸을 탐색할 때 사용
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

// for checking
void print_board(int board[MAX_N][MAX_N], int N) {
	cout <<endl<< "board printed ----" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << board[i][j] << " ";
		cout << endl;
	}
}

bool check_adjust(int r1, int c1, int r2, int c2) {
	int r = r1 - r2; r = r < 0 ? -r : r; // |r1-r2|
	int c = c1 - c2; c = c < 0 ? -c : c; // |c1-c2|

	if (r + c == 1) return true; // 인접함
	else return false;
}

int main() {
	struct Student students[MAX_ST]; // N^2명의 학생 정보, index = 학생 번호
	int board[MAX_N][MAX_N] = { 0, }; // 교실 칸, 0 = empty
	int orders[MAX_ST] = { 0, }; // orders[i] = j : i번째 학생의 번호는 j -> 만족도 계산 편하게 하려고

	/*  INPUT  */
	int N = 0; cin >> N;
	for (int order = 0; order < N * N; order++) {
		// 순서대로 학생 정보 입력 받기
		int num = 0;
		cin >> num; // 학생 번호: 1~ N^2
		orders[order] = num;
 		for (int l = 0; l < 4; l++) { // 좋아하는 학생 4명의 번호
			cin >> students[num].likes[l];
		}
	}


	/*  자리 배정  */
	for (int order = 0; order < N * N; order++) {
		// 학생 순서대로 자신에게 맞는 칸을 배정함
		// N*N 교실을 돌면서 max_likes, max_empty를 계산하고, 갱신
		// max 값으로 갱신할 때마다 row, col 값도 갱신
		int num = orders[order];
		struct Student st = students[num]; // 현재 순서인 학생
		int max_likes = -1, max_empty = -1;
		int row = 0, col = 0; // 현재 학생에게 배정해줄 칸

		// st의 pos를 (r, c)로 할지
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (board[r][c] != 0) continue; // 이미 자리가 있음
				int like_cnt = 0, empty_cnt=0;

				// 상-하-좌-우 인접한 칸들 검사하기 - 두 가지(likes, empty) 개수 구하려고
				// 1: 인접한 칸에 좋아하는 학생 숫자가 있는지 확인하고 like_cnt + 1
				// 2: 인접한 칸이 비어있는지 확인하고 empmty_cnt + 1
				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i], nc = c + dc[i];

					// 범위 검사
					if (nr > N || nr < 1) continue;
					if (nc > N || nc < 1) continue;

					// like_cnt 구하기
					for (int j = 0; j < 4; j++) {
						if (board[nr][nc] == st.likes[j]) {
							like_cnt++;
						}
					}

					// empty_cnt 구하기
					if (board[nr][nc] == 0) empty_cnt++;
				}
				bool update = false;

				// max 값을 비교하고 갱신하며 최적의 자리 찾기
				if (max_likes < like_cnt) { // 1번 규칙
					update = true;
				}
				else if (max_likes == like_cnt) { // 2번 규칙
					if (max_empty < empty_cnt) {
						update = true;
					}
					else if (max_empty == empty_cnt) { // 3번 규칙
						if (row > r) update = true;
						else if (row == r && col > c) update = true;
					}
				}
				if (update) {
					max_likes = like_cnt;
					max_empty = empty_cnt;
					row = r; col = c;
				}
			}
		}
		// row, col에 최적의 자리 값이 저장되어 있음
		board[row][col] = num; // board에 학생 번호 저장
		students[num].row = row; students[num].col = col; // 구조체에 자리 저장 -> 만족도 계산 편리성
	}

	// for checking students 배열 출력
	//for (int order = 0; order < N * N; order++) {
	//	cout << order << "th : " << students[order].num << " ---- ";
	//	for (int l = 0; l < 4; l++) { // 좋아하는 학생 4명의 번호
	//		cout << students[order].likes[l];
	//	}
	//	cout<<" ---- " << students[order].row << " , " << students[order].col << endl;
	//}

	//print_board(board, N);

	/*  만족도 계산  */
	int ans = 0; // 만족도 총합
	int score_ex[5] = { 0, 1, 10, 100, 1000 }; // 만족도 변환

	for (int n = 1; n <= N * N; n++) {
		int cnt = 0; // adjust like num count
		for (int l = 0; l < 4; l++) {
			int like_num = students[n].likes[l];
			if(check_adjust(students[like_num].row, students[like_num].col, students[n].row, students[n].col))
				cnt++;
		}
		cout << n << " -- " << cnt<<endl;
		ans += score_ex[cnt];
	}

	/*  출력  */
	cout << ans << endl;

	return 0;
}
