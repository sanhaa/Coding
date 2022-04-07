// BOJ 20056 마법사상어와파이어볼
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

const int MAXN = 60;
int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int even_d[] = { 0, 2, 4, 6 };
int odd_d[] = { 1, 3, 5, 7 };

vector<FIREBALL> nfireballs;
int ans = 0; // 파이어볼 질량 합

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) { // M개의 파이어볼 정보
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		FIREBALL f = FIREBALL(r, c, m, s, d);
		nfireballs.push_back(f);
		ans += m;
	}

	while (K--) {
		//cout << "\nmove move\n";
		// 각 칸 파이어볼 초기화
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		map[i][j].erase(map[i][j].begin(), map[i][j].end());
		//	}
		//}
		//vector<FIREBALL> map[MAXN][MAXN];
		vector<FIREBALL> fireballs = nfireballs;
		nfireballs.clear();

		bool visit[MAXN][MAXN] = { 0, };

		// 이동 명령
		for (vector<FIREBALL>::iterator iter = fireballs.begin(); iter != fireballs.end();iter++) {
			FIREBALL curf = *iter;
			//cout << iter->r <<" " << iter->c << " -> ";

			iter->r += dr[curf.d] * curf.s;
			iter->c += dc[curf.d] * curf.s;
			while (iter->r > N) iter->r -= N;
			while (iter->r < 1) iter->r += N;
			while (iter->c > N) iter->c -= N;
			while (iter->c < 1) iter->c += N;
			
			//cout << iter->r <<" " << iter->c <<" | "<<iter->m <<" "<<iter->s<<" "<<iter->s << endl;

			// 이동하고, 이동한 칸에 파이어볼 기록
			//map[iter->r][iter->c].push_back(*iter); // 값 바뀐걸로 잘 들어가겠지?
		}

		// 이동 완료 후 같은 칸에 파이어볼 2개 이상인지 검사
		for (vector<FIREBALL>::iterator iter = fireballs.begin(); iter != fireballs.end(); iter++) {
			FIREBALL f1 = *iter;
			if (visit[f1.r][f1.c]) continue;
			visit[f1.r][f1.c] = true;

			int nm = f1.m, ns = f1.s, is_even = (f1.d%2==0? 1: 0), same_dir = true, n=1;

			for(vector<FIREBALL>::iterator iter2 = iter+1; iter2 != fireballs.end();iter2++){
				FIREBALL f2 = *iter2;
				if (f1.r == f2.r && f1.c == f2.c) { // 같은 칸에 있는 파이어볼 모두 찾기
					nm += f2.m; ns += f2.s; n++;
					if (is_even && f2.d % 2 != 0) same_dir = false;
					else if (!is_even && f2.d % 2 == 0) same_dir = false;
				}
			}
			if (n >= 2) {
				//cout << f1.r << " " << f1.c << " has fireballs -" << n << endl;
				ans -= nm; // - sum(m)
				nm /= 5; ns /= n;
				int* nds = same_dir ? even_d : odd_d;
				if (nm == 0) continue;
				
				//cout << "4 fireballs split ----\n";
				// 파이어볼 4개 새로 만들어서 넣어주기
				for (int f = 0; f < 4; f++) {
					FIREBALL nf = FIREBALL(f1.r, f1.c, nm, ns, nds[f]);
					//cout << nf.r << " " << nf.c << " " << nf.m << " " << nf.s << " " << nf.d << endl;
					nfireballs.push_back(nf);
					ans += nm;
				}
			}
			else {
				nfireballs.push_back(f1);
			}
		}
	}
	ans = 0;
	for (auto it = nfireballs.begin(); it != nfireballs.end(); it++) {
		ans += it->m;
	}
	cout << ans << "\n";

	return 0;
}