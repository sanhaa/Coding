// BOJ 14503 로봇 청소기
// DFS
#include <iostream>
#include <stack>
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
stack<struct POS> st;
int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };

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
	st.push(POS(r, c, d));

	while (!st.empty()) {
		POS cur = st.top(); st.pop();

		// 2. search left
		int nd = cur.d;
		int cnt = 0, cleanf = 0; // clean flag
		for(cnt;cnt<4;cnt++){ // 4번 반복 명시
			nd = left_of(nd);
			int nr = cur.r + dr[nd];
			int nc = cur.c + dc[nd];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (map[nr][nc] == 0) {
				map[nr][nc] = -1; // clean
				ans++; cleanf = 1;
				st.push(POS(nr, nc, nd));
				break;
			}
		}
		if (cleanf == 0) {
			// 네방향 모두 벽 or 청소 = 후진 or 정지
			int nr = cur.r - dr[cur.d];
			int nc = cur.c - dc[cur.d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) break;
			if (map[nr][nc] == 1) break; // 벽: 정지
			st.push(POS(nr, nc, cur.d)); // else: 후진
		}
	}
	cout << ans << "\n";

	return 0;
}