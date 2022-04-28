// BOJ 12100 2048(Easy)
// 구현, 시뮬레이션
// C언어에서 함수의 인자로 전달하는 배열은 복사 X, 주소값으로 넘어감
// 배열을 복사해주고 싶으면 vector사용
// vector<> &v: 포인터 넘기기
// vector<> v: 복사해서 넘기기
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 30;
int N = 0;
int max_num = 0; // answer
// 상 하 좌 우
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void print_board(vector<vector<int>> board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

// 한 줄씩 처리
void line(vector<vector<int>>& board, int r, int c, int dir ) {
	int _r = r, _c = c;
	// 1. 합치기
	while (r >= 0 && c>=0 && r < N && c<N) {
		if (board[r][c] == 0) { // 숫자 있는 칸 찾기
			r -= dr[dir]; c -= dc[dir]; // 이동 방향 끝 칸부터 반대로
			continue;
		}
		int nr = r - dr[dir], nc = c - dc[dir];
		while (nr >= 0 && nr < N && nc >= 0 && nc < N) {
			if (board[nr][nc] == 0) {
				nr -= dr[dir];
				nc -= dc[dir];
				continue;
			}
			else if (board[nr][nc] == board[r][c]) { // 같은 수 합치기
				board[r][c] *= 2; // 2배
				// update answer
				if (max_num < board[r][c]) max_num = board[r][c];
				board[nr][nc] = 0;
			}
			r = nr; c = nc;
			break;
		}
		if (nr < 0 || nr >= N || nc < 0 || nc >= N) break;
	}
	// 2. 밀기
	r = _r; c = _c;
	while (r >= 0 && c >= 0 && r < N && c < N) {
		if (board[r][c] == 0) {
			r -= dr[dir]; c -= dc[dir];
			continue;
		}
		int val = board[r][c];
		int nr = r + dr[dir], nc = c + dc[dir];
		while (nr >= 0 && nr < N && nc >= 0 && nc < N) {
			if (board[nr][nc] == 0) {
				board[nr][nc] = val; // 빈칸으로 밀기
				board[nr - dr[dir]][nc - dc[dir]] = 0; // 이전 칸 빈칸 만들기
				nr += dr[dir]; nc += dc[dir];
			}
			else { // 빈칸이 아닌 다른 숫자거나, ...
				break;
			}
		}
		r -= dr[dir]; c -= dc[dir];
	}
}

// 이동 방향, 이동 횟수
void move(vector<vector<int>> board, int dir, int cnt) {
	if (cnt > 5) return;
	switch (dir)
	{
	case(0): // 상
		for (int c = 0; c < N; c++)
			line(board, 0, c, dir);
		break;
	case(1): // 하
		for (int c = 0; c < N; c++)
			line(board, N - 1, c, dir);
		break;
	case(2): // 좌
		for (int r = 0; r < N; r++)
			line(board, r, 0, dir);
		break;
	case(3): // 우
		for (int r = 0; r < N; r++)
			line(board, r, N - 1, dir);
		break;

	default:
		break;
	}

	// 다음 이동
	for (int nd = 0; nd < 4; nd++) {
		move(board, nd, cnt + 1);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<vector<int>> board;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int a = 0; cin >> a;
			temp.push_back(a);
			if (max_num < a) max_num = a;
		}
		board.push_back(temp);
	}

	for (int dir = 0; dir < 4; dir++) {
		move(board, dir, 1);
	}
	cout << max_num << "\n";

	return 0;
}