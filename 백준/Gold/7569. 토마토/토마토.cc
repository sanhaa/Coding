// BOJ 7569 토마토
// 3차원 배열?
// BFS
#include <iostream>

using namespace std;

struct TOMATO {
	int h = 0;
	int r = 0;
	int c = 0;
	int days = 0;
	TOMATO() {}
	TOMATO(int _h, int _r, int _c, int _d) {
		h = _h; r = _r; c = _c; days = _d;
	}
};

// 위 아래 앞 뒤 왼 오
int dh[] = { -1, 1, 0, 0, 0, 0 };
int dr[] = { 0,0,-1, 1, 0, 0 };
int dc[] = { 0,0,0,0,-1, 1 };

const int MAXN = 110;
int box[MAXN][MAXN][MAXN] = { 0, }; // tomato box
TOMATO que[MAXN * MAXN * MAXN];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M = 0, N = 0, H = 0;
	cin >> M >> N >> H;

	int remain = 0;

	int front = -1, rear = -1;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int a = 0; cin >> a;
				box[i][j][k] = a;
				if (a == 1)	que[++rear] = TOMATO(i, j, k, 0); // push
				else if (a == 0) remain++;
			}
		}
	} 

	int ans = 0, cnt = 0; // 최소 일수, 익은 토마토 개수
	while (front < rear) {
		TOMATO cur = que[++front]; // pop
		if (ans < cur.days) ans = cur.days;

		for (int i = 0; i < 6; i++) {
			int nh = cur.h + dh[i];
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			if (nh < 0 || nr < 0 || nc < 0 || nh >= H || nr >= N || nc >= M) continue;

			if (box[nh][nr][nc] == 0) {
				box[nh][nr][nc] = 1; // 익히기
				remain--; 
				que[++rear] = (TOMATO(nh, nr, nc, cur.days + 1));
			}
		}
	}
	if (remain != 0) cout << -1 << "\n";
	else cout << ans << "\n";

	return 0;
}