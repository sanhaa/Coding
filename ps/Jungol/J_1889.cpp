#include <iostream>
using namespace std;

typedef struct pos pos;
const int SIZE = 14;

int N = 0; // 퀸 개수, 보드의 행과 열 1 ~ 13
int ans = 0; // 정답, 퀸 배치 방법 수 

struct pos {
	int row = 0; // 1 ~ N 사용
	int col = 0; // 1 ~ N 사용
	pos() {};
	pos(int r, int c) {
		row = r; col = c;
	}
};

// for check
void print_solution(pos arr[]) {
	cout << "solution : \n";
	// 1 ~ N 사용
	for (int i = 1;i <= N;i++) {
		cout << "( " << arr[i].row << ", " << arr[i].col <<" )\n";
	}
}

// 이번에 놓을 수 있는 위치 구하기
void check_possible(pos arr[], int col[], int q) {
	// 행 : q에 이제 놓으려고
	// 열 : 1 ~ N 중에 세로, 대각선 겹치지 않는거

	// 놓으면 안되는 곳에 표시
	for (int i = 1;i < q;i++) {

		int arr_col = arr[i].col;
		int arr_row = arr[i].row;

		col[arr_col] = 1; // 같은 열 

		if (arr_col + (q - arr_row)  <= N) // \방향 대각선 검사
			col[arr_col + (q - arr_row)] = 1;

		if (arr_col - (q - arr_row) >= 1) // /방향 대각선 검사
			col[arr_col - (q - arr_row)] = 1;
	}
}

// arr : 현재까지 놓은 퀸 개수
void backtracking(pos arr[], int q) {
	if (q == N) {
		ans += 1;
		//print_solution(arr);
	}
	else {
		q += 1; // 인덱스 1 ~ N 까지 사용

		int blocked_col[SIZE] = { 0, };
		check_possible(arr, blocked_col, q);

		for (int i = 1;i <= N;i++) {
			if (blocked_col[i] == 0) { // 놓을 수 있는 자리
				arr[q] = pos(q, i);
				backtracking(arr, q);
			}
		}
	}
}

int main() {
	
	cin >> N;

	pos arr[SIZE]; // 1 ~ N사용
	backtracking(arr, 0);

	cout << ans << endl;

}
