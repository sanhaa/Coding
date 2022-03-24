/*
2021-04-22
J 1078 저글링 방사능 오염
BFS (레벨 구분) + queue 구현
*/
#include <iostream>
using namespace std;

#define MAX_SIZE 110
#define MAX_Q 1000

struct POS {
	int row = 0;
	int col = 0;
	int sec = 0; // 죽게 되는 시간
	POS() {};
	POS(int r, int c, int s) {
		row = r; col = c; sec = s;
	}
};

int main() {
	// 모든 열, 행 입력은 열, 행 순으로 

	int row = 0, col = 0;
	int jugs = 0; // 저글링 수
	int total_sec = 0;
	int map[MAX_SIZE][MAX_SIZE] = { 0, };
	cin >> col >> row;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			char c;
			scanf(" %c", &c);
			if (c == '1') {
				map[i][j] = 1;
			}
		}
	}

	POS start;
	cin >> start.col >> start.row;

	POS q[MAX_Q];
	int rear = -1, front = -1;
	q[++rear] = start; // push

	while (rear != front) {

		POS now = q[++front];
		map[now.row][now.col] = 0;

		if (total_sec < now.sec) {
			total_sec = now.sec;
		}
		
		// 상
		if (now.row-1 >0 && map[now.row - 1][now.col] == 1) {
			q[++rear] = POS(now.row - 1, now.col, now.sec + 1);
		}
		// 하
		if (now.row+ 1 <= row && map[now.row + 1][now.col] == 1) {
			q[++rear] = (POS(now.row + 1, now.col, now.sec + 1));
		}
		// 좌
		if (now.col - 1 > 0 && map[now.row][now.col - 1] == 1) {
			q[++rear] = (POS(now.row, now.col - 1, now.sec + 1));
		}
		// 우
		if (now.col + 1 <= col && map[now.row][now.col + 1] == 1) {
			q[++rear] = (POS(now.row, now.col + 1, now.sec + 1));
		}
	}

	// ********** 죽지 않은 저글링 세기
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (map[i][j] == 1) {
				jugs++;
			}
		}
	}

	cout << total_sec + 3 << endl << jugs << endl;

	return 0;
}
