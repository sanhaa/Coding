// BOJ 23289 온풍기 안녕
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct MACHINE {
	int r = 0;
	int c = 0;
	int dir = 0; // 1오 2왼 3위 4아래
	MACHINE() {}
	MACHINE(int _r, int _c, int _dir) {
		r = _r; c = _c; dir = _dir;
	}
};

struct AIR {
	int r = 0;
	int c = 0;
	int k = 0; // temp
	AIR() {}
	AIR(int _r, int _c, int _k) {
		r = _r; c = _c; k = _k;
	}
};

int dr[5][3] = { {0,0,0}, {-1,0,1}, {-1,0,1}, {-1,-1,-1}, {1, 1, 1} };
int dc[5][3] = { {0,0,0}, {1, 1, 1}, {-1,-1,-1}, {-1,0,1}, {-1,0,1} };

const int MAXR = 30;
int R = 0, C = 0, K = 0;
int temp_map[MAXR][MAXR] = { 0, };
vector<pair<int, int> > targets;
vector<MACHINE> machines;
int walls_hori[MAXR][MAXR];
int walls_verti[MAXR][MAXR];

bool is_wall(int r, int c, int rr, int cc) {
	// 두 칸 사이에 벽이 있는지
	if (r == rr) { // vertical walls
		if (c < cc) {
			if (walls_verti[r][c]) return true;
		}
		else {
			if (walls_verti[r][cc]) return true;
		}
	}
	else { //  c == cc
		if (r < rr) {
			if (walls_hori[rr][cc]) return true;
		}
		else {
			if (walls_hori[r][c]) return true;
		}
	}

	return false;
}

void print_map(int map[MAXR][MAXR], int R, int C) {
	cout << "-----------------------\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------\n\n";
}

void copy_arr(int src[MAXR][MAXR], int dst[MAXR][MAXR]) {
	for (int i = 0; i < MAXR; i++) {
		for (int j = 0; j < MAXR; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void process() {

	// 1. 온풍기 바람 
	for (int m = 0; m < machines.size(); m++) {
		MACHINE M = machines[m];
		queue<AIR> que;
		int nr = M.r + dr[M.dir][1];
		int nc = M.c + dc[M.dir][1];
		que.push(AIR(nr, nc, 5));
		temp_map[nr][nc] += 5;

		bool visit[MAXR][MAXR] = { false, };

		while (!que.empty()) {
			AIR cur = que.front(); que.pop();
			if (cur.k == 0) continue;

			for (int n = 0; n < 3; n++) {
				nr = cur.r + dr[M.dir][n];
				nc = cur.c + dc[M.dir][n];

				if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				if (visit[nr][nc]) continue;

				//cout << cur.r << " " << cur.c << " " << cur.k << " -> " << nr << " " << nc <<endl;

				// 벽 검사
				if (n == 1) {
					if (is_wall(cur.r, cur.c, nr, nc)) continue;
				}
				else {
					/* 대각선 칸일 때 검사*/
					int br = 0, bc = 0; // between 
					if (M.dir == 1 || M.dir == 2) {
						br = nr; bc = cur.c;
					}
					else { br = cur.r; bc = nc; }


					if (is_wall(cur.r, cur.c, br, bc)) continue;
					if (is_wall(br, bc, nr, nc)) continue;
				}

				visit[nr][nc] = true;
				que.push(AIR(nr, nc, cur.k - 1));
				temp_map[nr][nc] += cur.k - 1;
			}
		}

	}
	//cout << "Stage 1\n";
	//print_map(temp_map, R, C);

	// 2. 온도 조절
	int copied[MAXR][MAXR] = { 0, };
	copy_arr(temp_map, copied);

	bool visit[MAXR][MAXR] = { false, };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visit[i][j]) continue;
			visit[i][j] = true;

			for (int k = 1; k <= 4; k++) {
				int nr = i + dr[k][1];
				int nc = j + dc[k][1];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				if (visit[nr][nc]) continue;
				if (is_wall(i, j, nr, nc)) continue;

				int diff = temp_map[nr][nc] - temp_map[i][j];
				if (diff < 0) diff = -diff;
				diff /= 4;
				if (temp_map[nr][nc] > temp_map[i][j]) diff = -diff;

				copied[nr][nc] += diff;
				copied[i][j] -= diff;
			}
		}
	}

	//cout << "Stage 2\n";
	//print_map(copied, R, C);
	copy_arr(copied, temp_map);

	// 3. 제일 바깥쪽
	for (int i = 1; i < R - 1; i++) {
		if (temp_map[i][0] != 0) temp_map[i][0] -= 1;
		if (temp_map[i][C - 1] != 0) temp_map[i][C - 1] -= 1;
	}
	for (int j = 1; j < C - 1; j++) {
		if (temp_map[0][j] != 0) temp_map[0][j] -= 1;
		if (temp_map[R-1][j] != 0) temp_map[R-1][j] -= 1;
	}
	if (temp_map[0][0] != 0) temp_map[0][0] -= 1;
	if (temp_map[0][C - 1] != 0) temp_map[0][C - 1] -= 1;
	if (temp_map[R - 1][0] != 0) temp_map[R - 1][0] -= 1;
	if (temp_map[R - 1][C - 1] != 0) temp_map[R - 1][C - 1] -= 1;

	//cout << "Stage 3\n";
	//print_map(temp_map, R, C);

}

int main() {

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int a = 0; cin >> a;
			if (a == 0) continue;
			else if (a == 5) targets.push_back(make_pair(i, j));
			else {
				machines.push_back(MACHINE(i, j, a));
			}
		}
	}
	int W = 0; cin >> W;
	for (int w = 0; w < W; w++) {
		int x = 0, y = 0, t = 0;
		cin >> x >> y >> t;
		x -= 1; y -= 1; // 1~ 시작
		if (t == 0) walls_hori[x][y] = true;
		else walls_verti[x][y] = true;
	}

	int choco = 0;
	while (choco <= 100) {
		process();

		//cout << "after 1 process\n";
		//print_map(temp_map, R, C);

		choco++;

		// 칸 조사
		bool conti = false;
		for (int i = 0; i < targets.size(); i++) {
			int r = targets[i].first, c = targets[i].second;
			if (temp_map[r][c] < K) {
				conti = true; break; // process 계속 해야 함
			}
		}
		if (!conti) break;
	}

	cout << choco << endl;

	return 0;
}