#include <iostream>

using namespace std;

#define R 1
#define L 2
#define U 3
#define D 4

// x, y로 나타낸 위치
class POS {
public:
	int x = 0;
	int y = 0;

	POS() {};
	POS(int _x, int _y) { x = _x; y = _y; };
};

int N, M;
char board[10][10];
int res = 11;

void print_board() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void move(POS R_now, POS B_now, int dir, int cnt) {
	
	POS r_now = R_now;
	POS b_now = B_now;
	int in = 0; // 이번 탐색 중  red가 구멍에 들어가면 1

	if ( cnt >= res) {
		return;
	}

	// 움직이기
	if (dir == R) {
		while (board[R_now.y][R_now.x + 1] != '#') {
			if (board[R_now.y][R_now.x + 1] == 'O') {
				in = 1;
				break;
			}
			R_now.x++;
		}
		while (board[B_now.y][B_now.x + 1] != '#') {
			if (board[B_now.y][B_now.x + 1] == 'O') {
				return;
			}
			B_now.x++;
		}
	}
	else if (dir == L) {
		while (board[R_now.y][R_now.x - 1] != '#') {
			if (board[R_now.y][R_now.x -1] == 'O') {
				in = 1;
				break;
			}
			R_now.x--;
		}
		while (board[B_now.y][B_now.x - 1] != '#') {
			if (board[B_now.y][B_now.x -1] == 'O') {
				return;
			}
			B_now.x--;
		}
	}
	else if (dir == U) {
		while (board[R_now.y - 1][R_now.x] != '#') {
			if (board[R_now.y - 1][R_now.x] == 'O') {
				in = 1;
				break;
			}
			R_now.y--;
		}
		while (board[B_now.y - 1][B_now.x] != '#') {
			if (board[B_now.y - 1][B_now.x] == 'O') {
				return;
			}
			B_now.y--;
		}
	}
	else if (dir == D) {
		while (board[R_now.y + 1][R_now.x] != '#') {
			if (board[R_now.y + 1][R_now.x] == 'O') {
				in = 1;
				break;
			}
			R_now.y++;
		}
		while (board[B_now.y + 1][B_now.x] != '#') {
			if (board[B_now.y + 1][B_now.x] == 'O') {
				return;
			}
			B_now.y++;
		}
	}
	// 움직였는데 두 구슬의 좌표가 같을 때
	if (R_now.x == B_now.x && R_now.y == B_now.y) {
		int R_dist = abs(r_now.x - R_now.x) + abs(r_now.y- R_now.y);
		int B_dist = abs(b_now.x - B_now.x) + abs(b_now.y - B_now.y);
		if (R_dist > B_dist) {
			if (dir == R) R_now.x--;
			else if (dir == L) R_now.x++;
			else if (dir == U) R_now.y++;
			else if (dir == D) R_now.y--;
		}
		else {
			if (dir == R) B_now.x--;
			else if (dir == L) B_now.x++;
			else if (dir == U) B_now.y++;
			else if (dir == D) B_now.y--;
		}
	}

	//cout << dir << " " << cnt << " ) R_now : " << R_now.x << ", " << R_now.y;
	//cout << " | B_now : " << B_now.x << ", "<< B_now.y << endl;

	if (in) { // 빨강공 들어가면
		res = (cnt < res) ? cnt : res; // res 보다 cnt가 작을경우 업데이트
		return;
	}
	
	if ((R_now.x == r_now.x && R_now.y == r_now.y) && (B_now.x == b_now.x && B_now.y == b_now.y)) return;

	cnt++;
	if(dir != R && dir != L) move(R_now, B_now, R, cnt);
	if(dir != L && dir != R) move(R_now, B_now, L, cnt);
	if(dir != U && dir != D) move(R_now, B_now, U, cnt);
	if(dir != D && dir != U) move(R_now, B_now, D, cnt);
}


int main() {
	cin >> N >> M;

	POS R_now, B_now;
	// board 입력받기
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char c;
			cin >> c;
			if (c == 'R') R_now = POS(j, i);
			else if (c == 'B') B_now = POS(j, i);
			board[i][j] = c;
		}
	}
	//cout << "--------" << endl;
	move(R_now, B_now, R, 1);
	//cout << "--------" << endl;
	move(R_now, B_now, L, 1);
	//cout << "--------" << endl;
	move(R_now, B_now, U, 1);
	//cout << "--------" << endl;
	move(R_now, B_now, D, 1);

	if (res > 10) res = -1;
	cout << res << endl;
}