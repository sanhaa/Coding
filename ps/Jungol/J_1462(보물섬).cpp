/*
2021-04-23
J 1462 보물섬
알고리즘: BFS (레벨)
*/
#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 55

int R = 0, C = 0; // row and column
char map[MAX_SIZE][MAX_SIZE] = { 0, };

int dr[4] = {-1, 1, 0, 0}; // 행 상하
int dc[4] = {0, 0, -1, 1}; // 열 좌우

struct POS {
	int row = 0;
	int col = 0;
	int hours = 0; // level
	POS() {}
	POS(int r, int c, int d) {
		row = r; col = c; hours = d;
	}
};

int MAX(int a, int b) {
	return a > b ? a : b;
}

// map[row][col] 에서 탐색 시작, 레벨 바뀔 때마다 +1씩 하면서 시간 기록
int BFS(int row, int col) {

	char temp[MAX_SIZE][MAX_SIZE] = { 0, };
	// 원본 배열 복사
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			temp[i][j] = map[i][j];
		}
	}

	int hours = 0;
	queue<POS> q;
	q.push(POS(row, col, 0));

	while (!q.empty()) {
		POS now = q.front(); q.pop();
		
		if (temp[now.row][now.col] == 0) continue;
		else temp[now.row][now.col] = 0; // 방문 표시

		hours = MAX(hours, now.hours); // 최대 레벨 갱신
		
		// 상하좌우 탐색
		for (int d = 0;d < 4;d++) {
			// map  범위 검사
			if (now.row + dr[d] < 0 || now.row + dr[d] >= R || now.col + dc[d] < 0 || now.col + dc[d] >= C)  continue;

			if (temp[now.row + dr[d]][now.col + dc[d]] == 1) {
				q.push(POS(now.row + dr[d], now.col + dc[d], now.hours + 1));
			}
		}
	}
	
	return hours;
}

int main() {

	/*  input  */
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] == 'W') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}

	int answer = 0; // 최대 거리(시간_)
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (map[i][j] == 0)  continue;

			int ret = BFS(i, j); // map[i][j]에서 탐색을 시작해서, 가장 긴 거리(시간)을 반환
			answer = MAX(answer, ret);
		}
	}

	cout << answer << endl;

	return 0;
}
