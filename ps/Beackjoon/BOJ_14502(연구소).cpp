// BOJ 14502 연구소
// 알고리즘: BFS, Brute Force

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

const int MAX_N = 8;
int board[MAX_N][MAX_N] = { 0, };
int N = 0, M = 0;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int ans = 0;

enum INFO {
	EMPTY, WALL, VIRUS
};

// convert one integer to position pair
pii convert2pos(int x) {
	return make_pair(x / M, x % M);
}

void spread(pii w1, pii w2, pii w3) {
	queue<pair<int, int>> que;

	// copy board
	int _board[MAX_N][MAX_N] = { 0, };
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) {
			_board[i][j] = board[i][j];
			
			if(board[i][j] == VIRUS) que.push(make_pair(i, j));
		}
	}

	// make wall
	_board[w1.first][w1.second] = WALL; 
	_board[w2.first][w2.second] = WALL;
	_board[w3.first][w3.second] = WALL;

	while (!que.empty()) {
		pii now = que.front(); que.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nr = now.first + dr[dir];
			int nc = now.second + dc[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (_board[nr][nc] == EMPTY) {
				_board[nr][nc] = VIRUS;
				que.push(make_pair(nr, nc));
			}
		}
	}

	// size of safety area
	int size = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_board[i][j] == EMPTY) size++;
		}
	}
	if (size > ans) ans = size; // update max size of safety area
}

void print_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j];
		}
	}
}

int main() {
	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int NM = N * M;
	// set 3 walls 
	for (int w1 = 0; w1 < NM; w1++) {
		pii w1_pos = convert2pos(w1);
		if (board[w1_pos.first][w1_pos.second] != EMPTY) continue;
			
		for (int w2 = w1+1; w2 < NM; w2++) {
			pii w2_pos = convert2pos(w2);
			if (board[w2_pos.first][w2_pos.second] != EMPTY) continue;

			for(int w3 = w2+1; w3< NM; w3++){
				pii w3_pos = convert2pos(w3);
				if (board[w3_pos.first][w3_pos.second] != EMPTY) continue;
				// spread simulation
				spread(w1_pos, w2_pos, w3_pos);
			}
		}
	}

	cout << ans << endl;

	return 0;
}
