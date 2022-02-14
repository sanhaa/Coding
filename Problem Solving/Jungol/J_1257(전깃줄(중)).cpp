/*
2021-04-26
J 1257 전깃줄(중)
알고리즘: DP 기반 LIS
*/
#include <iostream>
using namespace std;

#define MAX_SIZE  100 //500010
int lines[MAX_SIZE] = { 0, };
int temp[MAX_SIZE] = { 0, };
int dp[MAX_SIZE] = { 0, };

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N = 0; cin >> N; // 전깃줄 개수 <= 10만
	int upper_range = 0;
	int lis = 0;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		lines[a] = b;
		temp[a] = b;
		upper_range = max(upper_range, a);
		upper_range = max(upper_range, b);
	}

	for (int i = 0; i <= upper_range; i++) {
		//if (lines[i] == 0) continue;
		cout <<i<<" : "<< lines[i] << endl;
	}
	int check_num = 0; int cnt = 0;
	for (int i = 0; i <= upper_range; i++) {
		if (lines[i] == 0) continue;
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (lines[i] > lines[j] && dp[i] < (dp[j]+1)) {
				dp[i] = dp[j] + 1;
			}
		}
		if (lis < dp[i]) {
			cout << "in  " << i << endl;
			lis = dp[i];
			if (check_num == lis) {
				cnt++;
			}
			if (check_num < lis) {
				check_num = lis;
				if(cnt == 0)
			}
		}
	}

	cout << N - lis << endl;

	for (int i = 0; i < upper_range; i++) {
		if (temp[i] == 0) continue;
		cout << i << endl;
	} 

	return 0;
}
