#include <iostream>
using namespace std;

int R = 0, C = 0;
int max_count = 1;
// A를 얻었으면 [0] = true;
bool visit_A[26] = { 0, };
char board[20][20] = { 0, };

// c라는 알파벳을 숫자로
#define TO_NUM(c) c-'A' 
typedef pair<int, int> coor; // 좌표

void DFS(coor v, int now_count) {
	char alph = board[v.first][v.second];
	visit_A[TO_NUM(alph)] = 1;
	//cout << alph << " ";
	max_count = max_count < now_count ? now_count : max_count;

	coor next_v;
	int fir = v.first;
	int sec = v.second;

	// up
	if ((fir - 1 >= 0) && visit_A[TO_NUM(board[fir - 1][sec])] == 0) {
		DFS(make_pair(fir - 1, sec), now_count + 1);
	}
	// down
	if ((fir + 1 < R) && visit_A[TO_NUM(board[fir + 1][sec])] == 0) {
		DFS(make_pair(fir + 1, sec), now_count + 1);
	}
	// left
	if ((sec - 1 >= 0) && visit_A[TO_NUM(board[fir][sec - 1])] == 0) {
		DFS(make_pair(fir, sec - 1), now_count + 1);
	}
	// right
	if ((sec + 1 < C) && visit_A[TO_NUM(board[fir][sec + 1])] == 0) {
		DFS(make_pair(fir, sec + 1), now_count + 1);
	}

	visit_A[TO_NUM(alph)] = 0;
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char b = 0;
			cin >> b;
			board[i][j] = b;
		}
	}

	coor start = make_pair(0, 0);

	DFS(start, 1);
	//cout << endl;

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (visit_A[i] == 1) ans++;
	}

	cout << max_count << endl;

	return 0;
}
