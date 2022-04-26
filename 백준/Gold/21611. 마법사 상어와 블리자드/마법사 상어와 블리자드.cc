// BOJ 21611 마법사 상어와 블리자드
#pragma warning (disable: 4996)
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 60;
int dr[] = { 0, -1, 1, 0, 0 }; // 상하좌우
int dc[] = { 0, 0, 0, -1, 1 };
int ndir[] = { 3, 2, 4, 1 }; // 구슬 번호 순서: 좌하우상
int mydir[] = { 0, 3, 1, 0, 2 }; // 2차원 -> 1차원 

int ans[4] = { 0, };

vector<int> to_vector(int map[MAXN][MAXN], int N) {
	vector<int> balls;
	int r = (N + 1) / 2, c = (N + 1) / 2;
	int len = 1, di = 0;
	int dir = ndir[di];
	balls.push_back(0);
	
	r += dr[dir]; c += dc[dir];
	balls.push_back(map[r][c]); // 위치 1
	di++; dir = ndir[di];

	r += dr[dir]; c += dc[dir];
	balls.push_back(map[r][c]); // 위치 2
	di++; dir = ndir[di];

	int line = 1;
	while (++line <= (N-1)*2) {

		for (int i = 1; i <= len; i++) {
			r += dr[dir]; c += dc[dir];
			if (r<1 || c<1 || r> N || c > N) break; // while도 break
			if (map[r][c] == 0) continue;
			balls.push_back(map[r][c]);
		}
		//  모서리 찍기
		r += dr[dir]; c += dc[dir];
		balls.push_back(map[r][c]);
		// 방향 전환
		di = (di + 1) % 4; dir = ndir[di];

		len = (line % 2 == 0 ? len: len+1);
	}

	return balls;
}


bool boom(vector<int> &balls) {
	bool flag = false;
	for (int i = 1; i < balls.size(); i++) {
		int j = i + 1;
		int cur = balls[i];
		while (j<balls.size()) {
			if (cur == balls[j]) {
				j++;
			}
			else break;
		}
		if (j - i >= 4) {
			ans[cur] += (j - i); // 폭발한 구슬 개수 세기
			balls.erase(balls.begin() + i, balls.begin() + j);
			flag = true;
		}
	}

	return flag;
}


int main() {

	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	int map[MAXN][MAXN] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) scanf("%d", &map[i][j]);
	}

	vector<int> balls = to_vector(map, N);
	
	for (int m = 1; m <= M; m++) {
		int d = 0, s = 0;
		scanf("%d %d", &d, &s);

		/* 1. 얼음 파편 */
		for (int i = 1; i <= s; i++) {
			int idx = (2 * i - 1) * (2 * i - 1) + i - 1 + mydir[d] * 2 * i;
			if (idx > N * N || idx >= balls.size()) break;
			balls[idx] = 0;
		}

		// 0 정리
		for (int i = 1; i < balls.size(); i++) {
			if (balls[i] == 0) {
				balls.erase(balls.begin() + i);
				i -= 1;
			}
		}

		/* 3. 폭발 */
		while (true) {
			bool ret = boom(balls);
			if (ret == false) break;
		}

		/* 4. 구슬 변화 */
		vector<int> new_balls; new_balls.push_back(0);
		int i = 1;
		while(i<balls.size()) {
			int j = i + 1;
			int cur = balls[i];
			while (j<balls.size()) {
				if (cur == balls[j]) j++;
				else break;
			}
			int A = j - i, B=cur;

			new_balls.push_back(A);
			if (new_balls.size() >= N * N) break;
			new_balls.push_back(B); 
			if (new_balls.size() >= N * N) break;

			i = j;
		}
		//cout << "after changing: \n";
		//print_map(new_balls);

		// copy
		balls.assign(new_balls.begin(), new_balls.end());
	}

	printf("%d\n", 1 * ans[1] + 2 * ans[2] + 3 * ans[3]);

	return 0;
}