/*
2021-04-23
J 1113 119 구급차
알고리즘: DFS?
*/
#include <iostream>
#include <stack>
using namespace std;

#define MAX_SIZE 110

enum DIR {
	NONE, UP, DOWN, LEFT, RIGHT
};

struct POS {
	int row = 0;
	int col = 0;
	int dir = NONE;
	int cnt = 0;

	POS() {}
	POS(int r, int c, int d, int _cnt) {
		row = r; col = c; dir = d; cnt = _cnt;
	}
};

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

POS goal;
int min_count = 987654321;
int R = 0, C = 0;
bool map[MAX_SIZE][MAX_SIZE] = { 0, };

int MIN(int a, int b) {
	return a < b ? a : b;
}

void DFS(POS p) {

	if (p.row == goal.row && p.col == goal.col) {
		min_count = MIN(min_count, p.cnt);
		return;
	}
	if (p.cnt > min_count) return;

	map[p.row][p.col] = 0; // 방문 표시

	for (int d = 0;d < 4;d++) {
		int nr = p.row + dr[d];
		int nc = p.col + dc[d];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

		if (map[nr][nc] == 1) {
			POS next = POS(nr, nc, d + 1, p.cnt);

			if (p.dir != NONE && p.dir != d + 1) { // 방향을 바꿔야 한다면
				next.cnt += 1; // 카운트 +1
			}

			//st.push(next);
			DFS(next);
			map[nr][nc] = 1; // 방문 표시
		}
	}

}

int main() {

	cin >> R >> C;
	cin >> goal.row >> goal.col;

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];
		}
	}

	DFS(POS(0, 0, 0, 0));

	cout << min_count << endl;

	return 0;
}
