/*
2021-04-28
J 1352 양팔저울
DP
*/
#include <iostream>
#include <stack>

using namespace std;

#define MAX_N 40
#define MAX_W 40010

char output[2] = { 'N', 'Y' };
int N = 0;
int weight[MAX_N] = { 0, };

// DP 테이블
// DP[i][j] : i번째 추까지 사용하여 무게 j 를 만들 수 있는가 (true, false)
bool DP[MAX_N][MAX_W] = { 0, };

int ABS(int a) {
	return a > 0 ? a : -a;
}

int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> N; // 추의 개수

	// 추의 무게 입력
	// 오름차순, 중복 존재
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
	}

	// Set DP table
	DP[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		DP[i][0] = 1;
		for (int j = 1; j < MAX_W; j++) {
			if (DP[i - 1][j] == 1)
				DP[i][j] = 1;
			else {
				DP[i][j] = (DP[i - 1][j + weight[i]]) || (DP[i - 1][ABS(j - weight[i])]);
			}
		}
	}

	// Q개의 구슬에 대한 답
	int Q = 0; cin >> Q; // 확인할 구슬의 개수 (최대 7개)
	for (int i = 0; i < Q; i++) {
		int m = 0; cin >> m;
		bool ans = 0;

		for (int j = 0; j <= N; j++) {
			if (DP[j][m]) {
				ans = 1;  break;
			}
		}

		cout << output[ans] << " ";
	}

	return 0;
}
