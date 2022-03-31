// BOJ 14503 로봇 청소기
// DFS
#include <iostream>
using namespace std;

struct POS {
	int r = 0;
	int c = 0;
	int d = 0;
	POS() {}
	POS(int _r, int _c, int _d) {
		r = _r; c = _c; d = _d;
	}
};

const int MAXN = 60;
int map[MAXN][MAXN] = { 0, }; // 0: empty, 1: wall
struct POS st[MAXN * MAXN] ;
int top = -1;
int dr[] = { -1, 0, 1, 0 };
int dc[] = {0, 1, 0, -1};

int left_of(int d) {
	int nd = d - 1;
	if (nd < 0) nd = 3;
	return nd;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	int r = 0, c = 0, d = 0;
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> map[i][j];

	int ans = 0; // 청소 영역 개수
	map[r][c] = -1; // 1. clean
	ans++;
	st[++top] = POS(r, c, d);

	while (top>=0) {
		POS cur = st[top--];
		
		// 2. search left
		int nd = cur.d;
		int cnt = 0;
		while (cnt<=4) {
			nd = left_of(nd);
			int nr = cur.r + dr[nd];
			int nc = cur.c + dc[nd];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (map[nr][nc] == 0) {
				map[nr][nc] = -1; // clean
				ans++;
				st[++top] = (POS(nr, nc, nd));
				break;
			}
			cnt++;
		}
		if (cnt >= 4) {
			// 네방향 모두 벽 or 청소 = 후진 or 정지
			int nr = cur.r - dr[cur.d];
			int nc = cur.c - dc[cur.d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) break;
			if (map[nr][nc] == 1) break; // 벽: 정지
			st[++top] = POS(nr, nc, cur.d); // 후진
		}
	}
	cout << ans << "\n";

	return 0;
}