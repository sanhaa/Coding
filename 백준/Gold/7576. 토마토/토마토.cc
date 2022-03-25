// BOJ 7576 토마토
// BFS
// 익은 토마토 + 익지 않은 토마토 정보 -> 모든 토마토가 익기 위한 최소 일수
// 인접 = (상하좌우 1칸)
// 최소 날짜, 처음부터 모두 익어있다면 0, 불가능 -1
#include <iostream>

using namespace std;

struct TMT { // 토마토 정보
	int r = 0;
	int c = 0;
	int d = 0; // 익은 날짜
	TMT() {}
	TMT(int _r, int _c, int _d) {
		r = _r; c = _c; d = _d;
	}
};

const int MAXN = 1010;
int board[MAXN][MAXN] = { -1, }; // 익음 1, 안익음 0, 빈칸 -1
TMT que[MAXN * MAXN]; 
int front = -1, rear = -1;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int min_days = 0;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M = 0, N = 0; // 가로(col), 세로(row) <= 1000
	cin >> M >> N;
	int blanks = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a = 0; cin >> a;
			board[i][j] = a;
			if (a == 1) que[++rear] = TMT(i, j, 0); // push
			if (a == -1) blanks++; // 빈칸 개수
		}
	}

	int cnt = 0;
	while (front < rear) {
		TMT cur = que[++front]; // pop
		if (min_days < cur.d) min_days = cur.d;
		cnt++; // 익은 토마토 개수 

		// 상하좌우 인접 토마토 익히기
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc>=M) continue;
			if (board[nr][nc] != 0) continue; // 이미 익었거나, 빈칸이면 건너뜀
			
			board[nr][nc] = 1; // 익히기
			que[++rear] = TMT(nr, nc, cur.d + 1);
		}
	}
	if (M * N - blanks > rear+1) cout << "-1\n";
	else cout << min_days << "\n";

	return 0;
}