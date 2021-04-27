/*
2021-04-27
J 2058 고돌이고소미
알고리즘: BFS
*/
#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 30

int MAX(int a, int b) {
	return a > b ? a : b;
}

int MIN(int a, int b) {
	return a < b ? a : b;
}

// 이차원 map 8방향 이동
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

struct POS {
	int row = 0;
	int col = 0;
	int sec = 0;
	POS() {};
	POS(int _row, int _col) {
		row = _row; col = _col;
	}
	POS(int _row, int _col, int _sec) {
		row = _row; col = _col; sec = _sec;
	}

	bool operator == (POS p) {
		return (row == p.row && col == p.col);
	}
};

bool check_range(int r, int c, int r2, int c2) {
	if (r == r2 - 1) {
		if (c == c2 - 1 || c == c2 || c == c2 - 1) return false;
	}
	else if (r == r2 + 1) {
		if (c == c2 - 1 || c == c2 || c == c2 - 1) return false;
	}
	else if (r == r2) {
		if (c == c2 - 1 || c == c2 || c == c2 - 1) return false;
	}

	return true;
}

int main() {
	/* 문제 조건 정리
	2차원 map 8방향 이동
	고돌이 고순이 둘 다 집에 도착하는 최소 시간( 워딩 '시간' 으로 통일)
	동시에 움직여야 접근 금지(주변 8곳) 판단이 쉬움 ?
	*/
	int N = 0; cin >> N;

	POS src1, src2;
	POS dst1, dst2;
	// 입력 순서:  행 렬
	cin >> src1.row >> src1.col >> dst1.row >> dst1.col;
	cin >> src2.row >> src2.col >> dst2.row >> dst2.col;

	int map[MAX_N][MAX_N] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 987654321;
	int flag = 0; // 고돌이 도착 여부
	// BFS
	queue<POS> q1; int visit1[MAX_N][MAX_N] = { 0, };// 고돌이
	queue<POS> q2; int visit2[MAX_N][MAX_N] = { 0, };// 고소미
	q1.push(src1);

	while (!q1.empty()) {
		POS now1 = q1.front(); q1.pop();
		cout << "1 : " << now1.row << " " << now1.col << endl;
		// 방문 체크
		if (visit1[now1.row][now1.col] == 1) continue;
		else visit1[now1.row][now1.col] = 1;
		
		if (now1 == dst1) {
			flag = 1;
		}

		q2.push(src2);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				visit2[i][j] = 0;
		}
		// 고소
		while (!q2.empty()) {
			POS now2 = q2.front(); q2.pop();

			// 방문 체크
			if (visit2[now2.row][now2.col] == 1) continue;
			else visit2[now2.row][now2.col] = 1;
			cout << "2 : " << now2.row << " " << now2.col << endl;

			if (now2 == dst2 && flag == 1) { // 종료 조건
				int sec = MAX(now1.sec, now2.sec);
				ans = MIN(ans, sec);
				break;
			}

			// 동시에 움직이려고...
			for (int i = 0; i < 8; i++) {
				int nr1 = now1.row + dr[i];
				int nc1 = now1.col + dc[i];
				if (flag == 1) {
					// 고돌이 도착했으면 움직일 필요가 없는데
					nr1 = dst1.row;
					nc1 = dst1.col;
				}
				if (nr1 <1 || nr1 > N || nc1 < 1 || nc1 > N) continue;
				if (map[nr1][nc1] == 1) continue; // next row, col 이 막혀있다

				for (int j = 0; j < 8; j++) {
					int nr2 = now2.row + dr[i];
					int nc2 = now2.col + dc[i];
					if (nr2 <1 || nr2 > N || nc2 < 1 || nc2 > N) continue;
					if (map[nr2][nc2] == 1) continue; // next row, col 이 막혀있다

					// 8방향 검사
					if (check_range(nr1, nc1, nr2, nc2) == false) continue;

					q2.push(POS(nr2, nc2, now2.sec + 1));
				}

				if(flag != 1) q1.push(POS(nr1, nc1, now1.sec + 1));
			}
		}
		flag = 0;
	}

	cout << ans << endl;

	return 0;
}
