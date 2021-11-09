// BOJ 3190
// 구현, 2차원 board 다루기, queue
// 틀린 이유 1: 사과가 없어진다는 조건을 빠트림, 
// 틀린 이유 2: 최대값을 제대로 고려하지 않아서 MAX_N * MAX_N이 아닌, MAX_N으로 설정함.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 110;
// idx: 1~100
int board[MAXN][MAXN] = { 0, }; // apple = 1
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int L_ni[4] = { 2, 3, 1, 0 }; // Left rotate, next idx(dir)
int R_ni[4] = { 3, 2, 0 ,1 }; // new dir idx(Right rotate) = R_ni[dir]

struct Snake {
	int dir = 3; // init to right
	int len = 1;
	pii head = make_pair(1, 1);
	pii body[MAXN*MAXN]; int front = -1; int back = -1; // -> queue
	// que push: body[++front] = x
	// que pop: x = body[++back]; body[back] = 0;
}snake;

int main() {
	int N = 0, K = 0, L = 0;
	/*  INPUT  */
	cin >> N >> K;
	for (int k = 0; k < K; k++) {
		int r = 0, c = 0;
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> L;
	vector<pair<int, char>> info;
	for (int l = 0; l < L; l++) {
		int i; char c;
		cin >> i >> c;
		info.push_back(make_pair(i, c));
	}

	/*  SOLVE  */
	snake.body[++snake.front] = make_pair(1, 1);
	int time = 1; // current time
	bool endf = false; 
  
	for (int vi = 0; vi<=info.size();vi++) {
		pair<int, char> value;
		if (vi == info.size()) {
			// 모든 info를 확인한 후에
			// 게임이 끝날 때까지 움직임(직진) 할 수 있도록 first=1만으로 설정
			value = make_pair(MAXN*MAXN, ' ');
		}
		else  value = info[vi];
		// move
		while (time <= value.first) {
			pii nhead = make_pair(snake.head.first + dr[snake.dir], snake.head.second + dc[snake.dir]); // next head
			
			// End 1. range
			if (nhead.first < 1 || nhead.first > N || nhead.second < 1 || nhead.second > N) {
				endf = true;  break;
			}
			// End 2. body
			for (pii b : snake.body) {
				if (b == make_pair(0, 0)) break;
				if (b.first == nhead.first && b.second == nhead.second) {
					endf = true; break;
				}
			}

			if (endf) break;

			snake.body[++snake.front] = nhead; // push(new head)
			snake.head = nhead;
			
			// apple O
			if (board[nhead.first][nhead.second]) {
				snake.len++;
				board[nhead.first][nhead.second] = 0; // delete apple
  			}
			// apple X
			else {
				snake.back++;
				snake.body[snake.back] = make_pair(-1,-1); // pop
			}
			time++;
		}

		// change direction
		if (value.second == 'L') {
			snake.dir = L_ni[snake.dir];
		}
		else if(value.second =='D'){
			snake.dir = R_ni[snake.dir];
		}
		else { endf = true; break; } // 원래는 없어도 됨

		if (endf) break;
	}

	/*  OUTPUT  */
	cout << time << endl;

	return 0;
}
