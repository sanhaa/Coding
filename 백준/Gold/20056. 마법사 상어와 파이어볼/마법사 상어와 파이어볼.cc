// BOJ 20056 마법사상어와파이어볼
// fireballs 벡터에 저장하지 않고 2차원 배열에 저장하면 안되나?
#include <iostream>
#include <vector>
using namespace std;

struct FIREBALL {
	int r = 0;
	int c = 0;
	int m = 0;
	int s = 0;
	int d = 0;
	FIREBALL() {}
	FIREBALL(int _r, int _c, int _m, int _s, int _d) {
		r = _r; c = _c; m = _m; s = _s; d = _d;
	}
};

struct FB {
	int m = 0, s = 0, d = 0;
	FB() {}
	FB(int _m, int _s, int _d) {
		m = _m; s = _s; d = _d;
	}
};

const int MAXN = 60;
int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int even_d[] = { 0, 2, 4, 6 };
int odd_d[] = { 1, 3, 5, 7 };

vector<FIREBALL> nfireballs;
int ans = 0; // 파이어볼 질량 합

void print_vector(vector<FB> board[MAXN][MAXN], int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << i << " " << j << " : ";
			for (FB v : board[i][j]) {
				cout << "("<<v.m << ", " << v.s << ", " << v.d << ") ";
			}
			cout << endl;
		}
	}
	cout << "------\n";
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;

	vector<FB> board[MAXN][MAXN];

	for (int i = 0; i < M; i++) { // M개의 파이어볼 정보
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		board[r][c].push_back(FB(m, s, d));
		ans += m;
	}
	
	while (K--) {
		vector<FB> new_board[MAXN][MAXN];

		// 각 파이어볼 이동
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < board[i][j].size(); k++) {
					FB fb = board[i][j][k];
					int nr = i + dr[fb.d]*fb.s, nc = j + dc[fb.d]*fb.s;
					while (nr < 1) nr += N; while (nr > N) nr -= N;
					while (nc < 1) nc += N; while (nc > N) nc -= N;
					new_board[nr][nc].push_back(FB(fb.m, fb.s, fb.d));
				}
			}
		}
		// copy
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				board[i][j] = new_board[i][j];
			}
		}
		//print_vector(board, N);

		// 각 칸에 2개 이상 있을 때
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int cnt = board[i][j].size();
				if (cnt < 2) continue;

				int nm = 0, ns = 0;
				int all_odd = -1 ;

				for (int k = 0; k < cnt; k++) {
					FB f = board[i][j][k];
					nm += f.m; ns += f.s;
					ans -= f.m;

					if (all_odd == -1) all_odd = (f.d % 2); // 홀수면 1, 짝수면 0 저장
					else if (all_odd == -2) continue; // 이미 different dir
					else {
						if (all_odd == 1 && (f.d % 2 == 0))  all_odd = -2;
						else if (all_odd == 0 && (f.d % 2 != 0)) all_odd = -2;
					}
				}

				// board[i][j] 소멸
				board[i][j].clear();
				
				vector<FB> new_fb(4); // 새로운 4개의 파이어볼
				nm = nm / 5; 
				if (nm == 0) continue; // 다른 칸

				ans += nm * 4;
				ns = ns / cnt;
				int* nd = (all_odd == -2 ? odd_d : even_d);

				for (int i = 0; i < 4; i++) {
					new_fb[i] = FB(nm, ns, nd[i]);
				}

				board[i][j].assign(new_fb.begin(), new_fb.end()); // copy
			}
		}
		 //print_vector(board, N);
	}

	cout << ans << "\n";

	return 0;
}