// BOJ 23288 주사위 굴리기 2
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 25;
enum DIR {
	EAST, SOUTH, WEST, NORTH
};
int dr[] = { 0,1,0,-1 }; // 동 남 서 북
int dc[] = { 1,0,-1,0 };
enum D { // 주사위 면
	TOP=0, BOT, FRT, BCK, LFT, RGT
};
int hori[] = { TOP, RGT, BOT, LFT }; // 동, 서 회전시 사용하는 면
int verti[] = { TOP, FRT, BOT, BCK }; // 남, 북 회전시 사용하는 면

// dice[D] = D 면에 있는 주사위 눈
int dice[] = { 1, 6, 5, 2, 4, 3 }; // 초기 주사위 상태
int map[MAXN][MAXN] = { 0, };
int N = 0, M = 0, K = 0;

void copy(int* src, int* dst, int len) {
	for (int i = 0; i < len; i++) {
		dst[i] = src[i];
	}
}

int score_of(int r, int c) {
	int B = map[r][c], C = 1;
	queue<pair<int, int> > que;
	que.push(make_pair(r, c));

	bool visit[MAXN][MAXN] = { false, };
	visit[r][c] = true;

	while (!que.empty()) {
		pair<int, int> cur = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i], nc = cur.second + dc[i];
			if (nr<1 || nc<1 || nr>N || nc>M) continue;
			if (visit[nr][nc]) continue;
			visit[nr][nc] = true;

			if (map[nr][nc] == B) {
				C++;
				que.push(make_pair(nr, nc));
			}
		}
	}
	return B * C;
}

void print_dice(int d[6]) {
	for (int i = 0; i < 6; i++) {
		cout << d[i] << " ";
	}
	cout << "\n-----\n";
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0; // 각 이동마다 점수의 합

	int r = 1, c = 1, dir = 0; // (1, 1) 시작, 방향: 동
	for (int k = 1; k <= K; k++) {
		// 1. 이동 방향으로 구르기
		int nr = r + dr[dir], nc = c + dc[dir];
		if (nr<1 || nc<1 || nr>N || nc>M) {
			dir = (dir + 2) % 4; // 이동방향 반대로
			nr = r + dr[dir]; nc = c + dc[dir];
		}

		// new_dice  copy
		int new_dice[6] = { 0, };
		copy(dice, new_dice, 6);

		if (dir == EAST) {
			for (int i = 0; i < 4; i++) {
				new_dice[hori[(i + 1)%4]] = dice[hori[i]];
			}
		}
		else if (dir == WEST) {
			for (int i = 0; i < 4; i++)
				new_dice[hori[i]] = dice[hori[(i + 1) % 4]];
		}
		else if (dir == SOUTH) {
			for (int i = 0; i < 4; i++)
				new_dice[verti[(i + 1) % 4]] = dice[verti[i]];
		}
		else if (dir == NORTH) {
			for (int i = 0; i < 4; i++)
				new_dice[verti[i]] = dice[verti[(i + 1) % 4]];
		}
		copy(new_dice, dice, 6);
		//print_dice(dice);
		
		// 2. 점수 획득
		ans += score_of(nr, nc);

		// 3. 다음 이동 방향 결정하기
		int A = dice[BOT], B = map[nr][nc];
		if (A > B) dir = (dir + 1) % 4;
		else if (A < B) dir = (dir + 3) % 4; // = dir - 1

		r = nr; c = nc;
	}

	cout << ans << "\n";

	return 0;
}