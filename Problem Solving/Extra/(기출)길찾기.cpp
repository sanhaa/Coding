/*
기출 : 길찾기
*/
#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 1010

int N = 0, M = 0;
int map[MAX_SIZE][MAX_SIZE] = { 0, };
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };


struct POS {
	int row = 0;
	int col = 0;

	POS() {};
	POS(int r, int c) {
		row = r; col = c;
	}
};

int temp[MAX_SIZE][MAX_SIZE] = { 0, };

bool find_route(POS start, POS end) {
	// temp 배열 사용 
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) temp[i][j] = map[i][j];
	}

	queue<POS> q;
	q.push(start);

	while (!q.empty()) {
		POS now = q.front(); q.pop();
		temp[now.row][now.col] = 0; // 방문 처리

		if (now.row == end.row && now.col == end.col) return true;

		// 상하좌우 
		for (int i = 0;i < 4;i++) {
			int nr = now.row + dr[i];
			int nc = now.col + dc[i];

			if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;

			if (temp[nr][nc]) {
				q.push(POS(nr, nc));
			}
		}
	}

	return false;
}

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T;t++) {
		N = 0; M = 0; // init
		for (int i = 0;i < MAX_SIZE;i++) {
			for (int j = 0;j < MAX_SIZE;j++) map[i][j] = 0;
		}

		int ans[MAX_SIZE] = { 0, };

		/*  input  */
		cin >> N >> M;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				int a = 0;
				cin >> a;
				if (a == 1) map[i][j] = 0;
				else map[i][j] = 1; // 이동 가능한 곳이 1
			}
		}

		for (int i = 0;i < M;i++) {
			POS A, B;
			cin >> A.row >> A.col >> B.row >> B.col;
			
			ans[i] = find_route(A, B);
		}

		cout << "#" << t;
		for (int i = 0;i < M;i++) {
			cout << " "<< ans[i];
		}
		cout << endl;
	}

	return 0;
}
