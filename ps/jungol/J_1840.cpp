#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 100;

//queue <struct pos> q;
bool board[SIZE][SIZE] = { 0, };
int M = 0, N = 0;

class pos {
public:
	int i = 0;
	int j = 0;
	int level = 0;
	pos() {};
	pos(int _i, int _j, int _level) {
		i = _i;
		j = _j;
		level = _level;
	}
};

pos q[100000];
int front = -1;
int rear = -1;


bool isFull() {
	if (rear >= SIZE - 1)
		return true;
	else
		return false;
}

bool isEmpty() {
	if (front == rear)
		return true;
	else
		return false;
}

void enQueue(pos val) {
	if (isFull())
		cout << "Queue Overflow \n";
	else
		q[++rear] = val;
}

pos deQueue() {
	if (isEmpty())
		cout << "Queue Underflow \n";
	else {
		//return q[++front];
		pos ret = q[++front];
		return ret;
	}
}


bool check(int i, int j) {
	if (board[i + 1][j] == 0) return true;
	if (board[i - 1][j] == 0) return true;
	if (board[i][j + 1] == 0) return true;
	if (board[i][j - 1] == 0) return true;

	return false;
}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	cin >> N >> M;
	int count = 0;
	int hours = 0;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || j == 0 || i == N - 1 || j == N - 1) continue;
			if ((board[i][j] == 1) && (check(i, j) == true)) {
				enQueue(pos(i, j, 1));
				count++;
			}
		}
	}
	
	cout << "count: " << count << endl;

	while (!isEmpty()) {

		pos now = deQueue();

		int i = now.i;
		int j = now.j;
		int level = now.level;
		cout << i << " " << j<<" "<<level << endl;


		if (board[now.i][now.j] == false) continue;

		if(check(i, j) == true)
			board[now.i][now.j] = false; // 치즈가 녹았다

		if (hours < level) {
			cout <<level<< " ------\n";
			hours = level;
			count = 0;
		}
		else if (hours == level) {
			count++;
		}

		// up
		if (i - 1 > 1 && board[i - 1][j] == 1) {
			//enQueue(make_pair(i - 1, j));
			enQueue(pos(i - 1, j, level+1));
		}
		// down
		if (i + 1 < N && board[i + 1][j] == 1) {
			//enQueue(make_pair(i + 1, j));
			enQueue(pos(i + 1, j, level+1));
		}
		// left
		if (j - 1 > 1 && board[i][j-1] == 1) {
			//enQueue(make_pair(i, j-1));
			enQueue(pos(i, j-1, level +1));
		}
		// right
		if (j + 1 > 1 && board[i][j+1] == 1) {
			//enQueue(make_pair(i, j+1));
			enQueue(pos(i, j+1, level+1));
		}
	}

	cout << hours << endl;
	cout << count << endl;

	return 0;
}
