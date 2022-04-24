// BOJ 23290 마법사 상어와 복제
// 4*4 격자: 1~4 인덱스 사용
#include <iostream>
#include <vector>
using namespace std;

const int N = 5; // 4*4 격자
int fdr[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }; // fish 방향 1~8
int fdc[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int sdr[] = { 0, -1, 0, 1, 0 }; // shark 방향 1~
int sdc[] = { 0, 0, -1, 0, 1 };

int sr = 0, sc = 0; // shark pos
vector<int> board[N][N]; // init?
vector<int> new_board[N][N];
int smell[N][N] = { 0, }; // 물고기 냄새가 남는 연습 횟수
int max_fish = -1;
int route[3] = { 0, };

void print_board(vector<int> b[N][N]) {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (b[i][j].size() == 0) cout << ".";
			else {
				for (int k = 0; k < b[i][j].size(); k++)
					cout << b[i][j][k];
			}
			cout << " ";
		}
		cout << endl;
	}
	cout << " ------------------ \n";
}

void print_board(int b[N][N]) {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << " ------------------ \n";
}

void shark_move(int depth, int removed_fish, int r, int c, int rt[3]) {
	if (depth == 3) {

		if (max_fish < removed_fish) {
			// better way to copy route to global var
			for (int i = 0; i < 3; i++) // copy route
				route[i] = rt[i];
			max_fish = removed_fish;
		}
		return;
	}

	// 상하좌우 인접
	for (int i = 1; i <= 4; i++) {
		int nr = r + sdr[i], nc = c + sdc[i];
		if (nr < 1 || nc < 1 || nr >= N || nc >= N) continue;

		vector<int> temp = new_board[nr][nc];
		new_board[nr][nc].clear();
		rt[depth] = i;
		shark_move(depth + 1, removed_fish + temp.size(), nr, nc, rt);
		new_board[nr][nc].assign(temp.begin(), temp.end());
	}
}

void fish_move() {
	// 1. 물고기 이동
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				int cur_d = board[i][j][k];
				int nd = cur_d;
				while (true) { // 이동 가능한 방향 나올 때까지 탐색, 이동
					int nr = i + fdr[nd];
					int nc = j + fdc[nd];
					if ((nr < 1 || nc < 1 || nr >= N || nc >= N) // 범위
						|| (nr == sr && nc == sc) // 상어 위치
						|| (smell[nr][nc] != 0)) { // 냄새 위치
						nd -= 1; // 반시계 회전
						if (nd == 0) nd = 8;
						if (nd == cur_d) {
							new_board[i][j].push_back(nd);
							break; // 이동 가능한 방향 없음
						}
						continue;
					}
					else { // 이동 가능한 방향
						new_board[nr][nc].push_back(nd);
						break;
					}
				}
			}
		}
	}
}

int main() {
	int M = 0, S = 0;
	cin >> M >> S;

	for (int i = 0; i < M; i++) {
		int x = 0, y = 0, dir = 0;
		cin >> x >> y >> dir;
		board[x][y].push_back(dir);
	}
	cin >> sr >> sc;

	for (int s = 1; s <= S; s++) {
		/* INIT */
		// new board init
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				new_board[i][j].clear();
			}
		}
		max_fish = -1;
		for (int i = 0; i < 3; i++) route[i] = 0;

		// 1. 물고기 이동
		fish_move();
		//cout << "fish moved:\n";
		//print_board(new_board);

		// 2. 상어 이동
		int temp[3] = { 0, };
		bool visit[N][N] = { 0, };

		shark_move(0, 0, sr, sc, temp);
		//cout << "shark moving: \n";
		for (int i = 0; i < 3; i++) {
			//cout << route[i] << " ";
			sr += sdr[route[i]];
			sc += sdc[route[i]];

			if (new_board[sr][sc].size() != 0) {
				new_board[sr][sc].clear();
				smell[sr][sc] = s;
			}
		}
		//cout << "-> " << sr << " " << sc << endl;
		//print_board(new_board);

		// 3. 물고기 냄새 제거
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (smell[i][j] == 0) continue;
				if (smell[i][j] <= s - 2) smell[i][j] = 0;
			}
		}
		//print_board(smell);

		// 4. 처음 물고기 복제
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				// copy
				for (int k = 0; k < new_board[i][j].size(); k++) {
					board[i][j].push_back(new_board[i][j][k]);
				}
			}
		}

		//cout << "copy origin: \n";
		//print_board(board);
	}

	// S번 연습 후 물고기 수 카운트
	int ans = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			ans += board[i][j].size();
		}
	}
	cout << ans << endl;

	return 0;
}
