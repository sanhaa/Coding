// BOJ 3190: 뱀
// board[1][1] ~ [N][N]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define APPLE 1
#define SNAKE 2

const int MAXN = 110;
// idx: 1~100
int board[MAXN][MAXN] = { 0, }; // apple = 1, snake = 2
int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
int L_ni[4] = { 2, 3, 1, 0 }; // Left rotate, next idx(dir)
int R_ni[4] = { 3, 2, 0 ,1 }; // new dir idx(Right rotate) = R_ni[dir]

struct Snake {
	int dir = 3; // init to right
	pii head = make_pair(1, 1);
	queue<pii> body;
}snake;


int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int N = 0, K = 0, L = 0;
	/*  INPUT  */
	cin >> N >> K;
	for (int k = 0; k < K; k++) {
		int r = 0, c = 0;
		cin >> r >> c;
		board[r][c] = APPLE;
	}
	cin >> L;
	vector<pair<int, char>> info;
	for (int l = 0; l < L; l++) {
		int i; char c;
		cin >> i >> c;
		info.push_back(make_pair(i, c));
	}

	/*  SOLVE  */
	snake.body.push(snake.head);
	board[snake.head.first][snake.head.second] = SNAKE; // snake 

	int time = 1; // current time
	bool endf = false;
	for (int vi = 0; vi <= info.size(); vi++) {
		pair<int, char> value;
		if (vi == info.size()) {
			// 모든 info를 확인한 후에 = 더이상 방향 전환 없을 때
			// 게임이 끝날 때까지 움직임(직진) 할 수 있도록 first=1만으로 설정
			value = make_pair(MAXN * MAXN, ' ');
		}
		else  value = info[vi];

		// move
		while (time <= value.first) {
			pii nhead = make_pair(snake.head.first + dr[snake.dir], snake.head.second + dc[snake.dir]); // next head

			// End 1. range
			// End 2. body
			if (nhead.first < 1 || nhead.first > N || nhead.second < 1 || nhead.second > N
				|| board[nhead.first][nhead.second] == SNAKE) {
				endf = true;  break;
			}

			// apple X
			if (board[nhead.first][nhead.second]!=APPLE) {
				pii tail = snake.body.front();
				board[tail.first][tail.second] = 0; // 꼬리 당기기
				snake.body.pop();
			}

			board[nhead.first][nhead.second] = SNAKE; 

			snake.body.push(nhead);
			snake.head = nhead;

			time++;
		}
		
		if (endf) break;

		// change direction
		if (value.second == 'L') {
			snake.dir = L_ni[snake.dir];
		}
		else if (value.second == 'D') {
			snake.dir = R_ni[snake.dir];
		}
	}

	/*  OUTPUT  */
	cout << time << endl;

	return 0;
}