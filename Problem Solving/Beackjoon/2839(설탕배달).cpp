// BOJ 2839 설탕배달
// 알고리즘: DP

#include <iostream>

using namespace std;

const int MAX = 5010;
int dp[MAX] = { 0, }; // dp[i] = 무게 i를 만들때 필요한 최소 봉지 개수

int mmin(int a, int b) {
	return (a < b ? a : b);
}

int main() {
	int N = 0; cin >> N;

	dp[3] = 1; dp[4] = 0; dp[5] = 1;

	for (int i = 6;i <= N;i++) {
		
		if (dp[i - 3] != 0) dp[i] = dp[i - 3] + 1;
		if (dp[i - 5] != 0) {
			if (dp[i] == 0) dp[i] = dp[i - 5] + 1; // dp[i]
			else dp[i] = mmin(dp[i], dp[i - 5] + 1);
		}
	}

	cout << (dp[N]!=0? dp[N]:-1) << endl;
	return 0;
}
