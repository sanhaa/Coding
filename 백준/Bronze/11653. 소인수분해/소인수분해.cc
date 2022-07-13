// BOJ 11653 소인수분해
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0; cin >> N;
	int div = 2;
	while (N > 1) {
		while (true) {
			if (N % div == 0) {
				cout << div << "\n";
				N /= div;
			}
			else break;
		}
		div++;
	}

	return 0;
}