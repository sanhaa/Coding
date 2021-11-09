/*
BOJ 2167: 2차원 배열의 합
DP
*/
#include <iostream>

using namespace std;

#define MAX_SIZE 310

int main() {
	int N, M , K; 
	int arr[MAX_SIZE][MAX_SIZE] = { 0, };// 입력 배열
	int S[MAX_SIZE][MAX_SIZE] = { 0, }; // arr[i][j] 까지 누적합

	/*  input  */
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			S[i][j] = S[i][j - 1] + arr[i][j];
		}
	}

	// set S[] row 방향
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			S[i][j] = S[i - 1][j] + S[i][j];
		}
	}

	cin >> K;
	for (int k = 0; k < K; k++) {
		int i, x, j, y;
		cin >> i >> j >> x >> y;

		int ans = S[x][y] - S[i - 1][y] - S[x][j - 1] + S[i - 1][j - 1];
		cout << ans << "\n";
	}

	return 0;
}
