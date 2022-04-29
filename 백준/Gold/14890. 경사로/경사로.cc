// BOJ 14890 경사로
#include <iostream>
using namespace std;

const int MAXN = 110;
int N = 0, L = 0;
int board[MAXN][MAXN];

bool is_avail(int _r, int _c, int dr, int dc, bool placed[MAXN]) {
	int r = _r, c = _c;

	while (true) {
		int nr = r , nc = c, len = 1;

		while (true) {
			nr += dr; nc += dc;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) break;

			int diff = board[nr][nc] - board[r][c];

			if (diff == 0) {
				len++;
				continue;
			}

			else if (diff == 1) {

				// 1. 길이
				if (len < L) {
					return false;
				}

				for (int l = 1; l <= L; l++) {
					pair<int, int> target = make_pair(nr - l * dr, nc - l * dc);

					// 2. 범위
					if (target.first < 0 || target.second < 0 || target.first >= N || target.second >= N) {
						return false;
					}
					// 3. 이미 설치된
					int pi = 0;
					if (dr == 0) pi = target.second; // row 검사 = col을 인덱스로 검사
					else pi = target.first;
					if (placed[pi]) {
						return false;
					}
				}

				// 사다리 설치 완료
				// placed 표시
				for (int l = 1; l <= L; l++) {
					pair<int, int> target = make_pair(nr - l * dr, nc - l * dc);

					int pi = 0;
					if (dr == 0) pi = target.second; // row 검사 = col을 인덱스로 검사
					else pi = target.first;
					placed[pi] = true;
				}
				len = 0; break;
			}
			else if (diff >= 2 || diff <= -2) {
				return false;
			}
			else break;
		}
		// 사다리 설치 후 r, c 조절 
		r = nr; c = nc;
		if (r < 0 || c < 0 || r >= N || c >= N) break;
	}

	return true;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> board[i][j];

	int ans = 0;

	// row 한 줄씩 확인
	for (int r = 0; r < N; r++) {
		bool placed[MAXN] = { 0, }; // 경사로 놓은 위치 체크

		bool r1 = is_avail(r, 0, 0, 1, placed);
		bool r2 = is_avail(r, N - 1, 0, -1, placed); // 반대방향
		if (r1 && r2) {
			ans++;
		}
	}

	// col 한 줄씩 확인
	for (int c = 0; c < N; c++) {
		bool placed[MAXN] = { 0, };

		bool r1 = is_avail(0, c, 1, 0, placed);
		bool r2 = is_avail(N-1, c, -1, 0, placed);
		if (r1 && r2) {
			ans++;
		}
	}
	cout << ans << "\n";

	return 0;
}