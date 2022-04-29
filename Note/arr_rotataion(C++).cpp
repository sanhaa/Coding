// C++ 2차원 배열 회전하기
#include <iostream>

using namespace std;

const int MAXN = 3;

void print_map(int map[MAXN][MAXN], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void rotate_90(int from[MAXN][MAXN], int to[MAXN][MAXN], int N) {
	
	for (int c = 0; c < N; c++) {
		for (int r = 0; r < N; r++) {
			to[c][N - 1 - r] = from[r][c];
		}
	}
}

int main() {

	int map[MAXN][MAXN] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int N = 3;
	print_map(map, N);

	int map90[MAXN][MAXN] = { 0, }, map180[MAXN][MAXN] = { 0, }, map270[MAXN][MAXN] = { 0, };
	
	rotate_90(map, map90, N);
	print_map(map90, N);

	rotate_90(map90, map180, N);
	print_map(map180, N);

	rotate_90(map180, map270, N);
	print_map(map270, N);

	return 0;
}
