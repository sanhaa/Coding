// C++ 2차원 배열 회정하기
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;
int N = 0, M = 0;
int maxv = 0;

pair<int, int> tetro[7][4] = {
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // ㅡ
	{{0, 0}, {1, 0}, {0, 1}, {1, 1}}, // ㅁ
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}}, // ㄴ
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}}, // 뒤집은 ㄴ
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}}, // ㄹ
	{{0, 0}, {1, 0}, {1, -1}, {2, -1}},// 뒤집은 ㄹ
	{{0, 0}, {0, 1}, {1, 1}, {0, 2}} // ㅜ
};

void print_vector(vector<vector<int>> v) {
	cout << "--\n";
	for (int i = 0; i < v.size(); i++) {
		for (int j=0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
// from의 row size: from.size()
// from의 col size: from[0].size()
vector<vector<int>> rotate_90(vector<vector<int>> from) {
	int COL = from[0].size(), ROW = from.size();
	// from의 (col, row) 크기만큼 초기화
	vector<vector<int>> new_board(COL, vector<int>(ROW, 0)); 

	for (int c = 0; c < COL; c++) {
		for (int r = 0; r < ROW; r++) {
			new_board[c][ROW - 1 - r] = from[r][c];
		}
	}
	return new_board;
}

void solve(vector<vector<int>> board, int depth) {
	if (depth > 4) return;

	int ROW = board.size(), COL = board[0].size();

	// start point
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			// (i, j) 점에서 7가지 모양 확인
			for (int t = 0; t < 7; t++) {
				int cur_sum = 0, possible = 1;
				for (int tt = 0; tt < 4; tt++) { // 각 모양에서 4개의 좌표 정보
					int ni = i + tetro[t][tt].first, nj = j + tetro[t][tt].second;
					if (ni < 0 || nj < 0 || ni >= ROW || nj >= COL) {
						possible = 0; break;
					}
					cur_sum += board[ni][nj];
				}
				// 이번 모양 
				if (!possible) continue;
				if (cur_sum > maxv) maxv = cur_sum;
			}
		}
	}

	vector<vector<int>> new_board = rotate_90(board);
	solve(new_board, depth + 1);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<vector<int>> board;
	board.assign(N, vector<int>(M, 0)); // 2차원 벡터 N*M 초기화

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// 재귀로 board를 90도씩 회전해서 모든 방향 확인
	solve(board, 1);
	cout << maxv << "\n";

	return 0;
}