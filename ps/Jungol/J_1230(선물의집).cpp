/*
2021-04-22
J 1230 선물의 집
시작점과 도착점에도 선물이 있을 수 있는걸 고려하지 않음
재귀 들어가서 처리하면 코드가 간편해진다
*/
#include <iostream>
using namespace std;

#define MAX_N 11

struct POS {
	int x = 0;
	int y = 0;
	POS() {};
	POS(int _x, int _y) {
		x = _x; y = _y;
	}
};

int MAX(int a, int b) {
	return a > b ? a : b;
}

int max_present = 0;
int n = 0;
int map[MAX_N][MAX_N] = { 0, };

void backtracking(POS p, int present) {
	int get = 0; // 이번 칸에서 얻은 선물 0 or 1

	int temp = map[p.y][p.x];
	if (temp == 2) get = 1;

	// 출구 도착
	if (p.x == n - 1 && p.y == n - 1) {
		//cout << "- END -" << endl;
		max_present = MAX(max_present, present+get);
		return;
	}

	map[p.y][p.x] = 1;
	
	// 상
	if (p.y-1 >= 0 && map[p.y-1][p.x] != 1) {
		backtracking(POS(p.x, p.y-1), present + get);
	}

	// 하
	if (p.y+1 < n && map[p.y+1][p.x] != 1) {
		backtracking(POS(p.x, p.y+1), present + get);
	}

	// 좌
	if (p.x-1 >= 0 && map[p.y][p.x-1] != 1) {
		backtracking(POS(p.x-1, p.y), present + get);
	}

	// 우
	if (p.x+1 < n && map[p.y][p.x+1] != 1) {
		backtracking(POS(p.x+1, p.y), present + get);
	}

	map[p.y][p.x] = temp;
}


int main() {
	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	// 입구 [0][0] 출발
	backtracking(POS(0, 0), 0);

	cout << max_present << endl;

	return 0;
}
