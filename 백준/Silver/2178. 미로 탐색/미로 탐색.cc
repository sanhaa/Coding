// BOJ 2178 미로탐색
// BFS, 풀이 확인
#include <iostream>

using namespace std;

struct POS {
	int row = 0;
	int col = 0;
	int cnt = 0;

	POS() {};
	POS(int _row, int _col, int _cnt) {
		row = _row;
		col = _col;
		cnt = _cnt;
	};
};

const int MAXN = 100;
int board[MAXN][MAXN] = { 0, };
POS q[MAXN * MAXN];

// 상하좌우
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == '1') board[i][j] = 1;
		}
	}
	// (0, 0) -> (N-1, M-1)
	int front = -1, rear = -1;
	q[++rear] = POS(0,0,1); // push

	while (front < rear) { // !q.empty()
		POS cur = q[++front]; // pop
		
		if (cur.row == N - 1 && cur.col == M - 1) {
			// 도착
			cout << cur.cnt << endl;
			break;
		}
		// 다음 상하좌우
		for (int d = 0; d < 4; d++) {
			int nr = cur.row + dr[d];
			int nc = cur.col + dc[d];
			if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
				if (board[nr][nc]) {
					board[nr][nc] = 0; // visit
					q[++rear] = POS(nr, nc, cur.cnt + 1); // push
				}
			}
		}
	}


	return 0;
}