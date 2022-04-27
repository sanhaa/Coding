/*
2021-04-22
백준 퇴사
Brute Force
*/
#include <iostream>
using namespace std;

#define MAX_N 16

int max_profit = 0;
int N = 0;
int T[MAX_N] = { 0, };
int P[MAX_N] = { 0, };

int MAX(int a, int b) {
	return a > b ? a : b;
}

void BruteForce(int d, int profit) {

	max_profit = MAX(profit, max_profit);

	for (int i = d + T[d]; i <= N; i++) {
		if(i + T[i] <= N + 1)
			BruteForce(i, profit + P[i]);
	}

	return;
}

int main() {
	cin >> N;

	// 1 ~ N 일의 정보
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1)
			BruteForce(i, P[i]);
	}

	cout << max_profit << endl;

	return 0;
}