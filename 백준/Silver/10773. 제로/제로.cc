// BOJ 10733 제로
// 스택
#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K = 0; cin >> K;
	int st[100000], top = -1;
	long long int sum = 0;

	for (int i = 0; i < K; i++) {
		int cur = 0; cin >> cur;
		if (cur == 0) {
			sum -= st[top--]; // pop
		}
		else {
			sum += cur;
			st[++top] = cur; // push
		}
	}
	cout << sum << "\n";

	return 0;
}