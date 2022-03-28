// BOJ 10026 적록색약
// 그래프
#pragma warning (disable: 4996)

#include <iostream>
#include <vector>

using namespace std;

enum COLOR {
	R, G, B
};

struct POS {
	int r = 0;
	int c = 0;
	int color = -1;
	POS() {}
	POS(int _r, int _c,  int _color) {
		r = _r; c = _c; color = _color;
	}
};

const int MAXN = 110;
int N = 0;
int dr[] = { -1, 1, 0, 0, };
int dc[] = { 0,0,-1, 1 };

int get_areas(int board[MAXN][MAXN]) {
	int areas = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == -1) continue;
			
			vector<POS> st;
			st.push_back(POS(i, j, board[i][j]));
			board[i][j] = -1; // visit

			while (!st.empty()) {
				POS cur = st.back(); st.pop_back();
				for (int d = 0; d < 4; d++) {
					int nr = cur.r + dr[d];
					int nc = cur.c + dc[d];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
					if (board[nr][nc] == -1) continue;
					if (board[nr][nc] == cur.color) {
						st.push_back(POS(nr, nc, board[nr][nc]));
						board[nr][nc] = -1; // visit
					}
				}
			}
			areas++;
		}
	}
	return areas;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int board[MAXN][MAXN] = { 0, };
	int board_rg[MAXN][MAXN] = { 0, };

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; 
			scanf(" %c", &c);
			if (c == 'R') {
				board[i][j] = R;
				board_rg[i][j] = R;
			}
			else if (c == 'G') {
				board[i][j] = G;
				board_rg[i][j] = R;
			}
			else {
				board[i][j] = B;
				board_rg[i][j] = B;
			}
		}
	}
	
	int areas = get_areas(board); // 구역 개수
	int areas_rg = get_areas(board_rg); // 색약이 인식하는 구역 개수
	printf("%d %d\n", areas, areas_rg);

	return 0;
}