// BOJ 14500 테트로미노
// 그래프 탐색으로 할려면 ㅗ 모양을 못찾는데...
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 510;
int N = 0, M = 0;
int board[MAXN][MAXN] = { 0, };
bool visited[MAXN][MAXN] = { 0, };

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int max_sum = 0;

struct POS {
	int row = 0;
	int col = 0;
	int nblocks = 0;
	int sum = 0;
	POS() {};
	POS(int _row, int _col, int _nblocks, int _sum) {
		row = _row; col = _col; nblocks = _nblocks; sum = _sum;
	}
};

void solution(POS cur) {
	if (cur.nblocks == 4) {
		if (max_sum < cur.sum) max_sum = cur.sum;
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nr = cur.row + dr[dir];
		int nc = cur.col + dc[dir];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
		if (visited[nr][nc]) continue;

		visited[nr][nc] = true;
		solution(POS(nr, nc, cur.nblocks + 1, cur.sum + board[nr][nc]));
		visited[nr][nc] = false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// start point
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// ㅗ 모양
			POS cur = POS(i, j, 1, board[i][j]);
			int min = 1000;
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur.row + dr[dir];
				int nc = cur.col + dc[dir];
				if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				cur.nblocks++;
				cur.sum += board[nr][nc];
				if (min > board[nr][nc]) min = board[nr][nc];
			}
			if (cur.nblocks == 4 && max_sum < cur.sum) max_sum = cur.sum;
			else if (cur.nblocks == 5) {
				cur.sum -= min; 
				if (max_sum < cur.sum) max_sum = cur.sum;
			}
			// ㅡ ㄴ ㅁ ㄹ 모양은 DFS
			visited[i][j] = true;
			solution(POS(i, j, 1, board[i][j]));
			visited[i][j] = false;
		}
	}

	cout << max_sum << endl;

	return 0;
}