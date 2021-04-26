/*
2021-04-26
J_1082: 화염에서탈출
알고리즘: BFS + queue 구현
*/
#include <iostream>
//#include <queue>
using namespace std;

#define MAX_SIZE 55
#define MAX_ARR 5000
#define INF 987654321

struct POS {
	int row = 0;
	int col = 0;
	int minute = 0;

	POS() {}
	POS(int r, int c) {
		row = r; col = c;
	}
	POS(int r, int c, int m) {
		row = r; col = c; minute = m;
	}
};

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int R = 0, C = 0;
char map[MAX_SIZE][MAX_SIZE] = { 0, };
POS s_pos;
POS fires[MAX_ARR]; int fi = 0;

int MIN(int a, int b) {
	return a < b ? a : b;
}

int BFS() {
	int ret = INF;
	//queue<POS> q;
	//q.push(s_pos);
	POS q[MAX_ARR];
	int front = -1, rear = -1;
	q[++rear] = s_pos;

	int prev_m = -1;

	while (/*!q.empty()*/front != rear) {
		//POS now = q.front(); q.pop();
		POS now = q[++front];

		if (map[now.row][now.col] == 'D') {	 // 종료 조건
			ret = MIN(ret, now.minute);
		}

		if (map[now.row][now.col] != '.') {
			continue;
		}

		map[now.row][now.col] = ','; // 방문 처리

		// 불 옮기기
		if (prev_m != now.minute) { // 이전과 레벨이 같으면 불 위치가 같다.
			int fires_count = fi;
			for (int i = 0; i < fires_count; i++) {
				POS fire_now = fires[i];

				for (int i = 0; i < 4; i++) {
					int nr = fire_now.row + dr[i];
					int nc = fire_now.col + dc[i];

					if (map[nr][nc] == '.' || map[nr][nc] == ',') {
						map[nr][nc] = '*';
						fires[fi++] = POS(nr, nc);
					}
				}
			}
		}

		// 현재 위치에서 갈 수 있는 위치
		for (int i = 0; i < 4; i++) {
			int nr = now.row + dr[i];
			int nc = now.col + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

			if (map[nr][nc] == '.' || map[nr][nc] == 'D') {
				//q.push(POS(nr, nc, now.minute + 1));
				q[++rear] = POS(nr, nc, now.minute + 1);
			}
		}

		prev_m = now.minute;
	}

	if (ret == INF) return -1;
	else return ret;
}

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] == 'S') {
				map[i][j] = '.';
				s_pos = POS(i, j);
			}
			else if (map[i][j] == '*') {
				fires[fi++] = POS(i, j);
			}
		}
	}

	int ret = BFS();
	if (ret == -1) cout << "impossible" << endl;
	else cout << ret << endl;

	return 0;
}
