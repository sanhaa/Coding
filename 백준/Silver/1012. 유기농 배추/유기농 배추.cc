// BOJ 1012 유기농 배추
// BFS, que
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 51;

// 상 하 좌 우
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T = 0;
	cin >> T;
	while (T--) {
		int N = 0, M = 0, K = 0, cnt=0;
		cin >> M >> N >> K;

		int board[MAXN][MAXN] = { 0, };
		for (int i = 0; i < K; i++) {
			int r = 0, c = 0;
			cin >> c >> r; // x, y 순서로
			board[r][c] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j]) {
					vector<pair<int, int> > q;
					q.push_back(make_pair(i, j));
					board[i][j] = 0; // visit check

					while (!q.empty()) { // 현재 배추와 인접한 모든 배추 찾기
						pair<int, int> cur = q.front(); q.erase(q.begin()); // pop

						// 상하좌우
						for (int d = 0; d < 4; d++) {
							int nr = cur.first + dr[d];
							int nc = cur.second + dc[d];
							if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue; 
							if (board[nr][nc]) {
								q.push_back(make_pair(nr, nc)); // push
								board[nr][nc] = 0; // visit check
							}
						}
					}
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}