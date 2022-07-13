// BOJ 2581 소수
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20000;

int main() {

	int M = 0, N = 0; cin >> M >> N;
	int sum = 0, min = MAXN;
	
	if (M <= 2) M = 2;

	for (int x = M; x <= N; x++) {
		bool is_prime = true;
		for (int div = 2; div < x; div++) {
			if (x % div == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			sum += x;
			if (min == MAXN) min = x;
		}
	}
	if (sum == 0) cout << "-1\n";
	else cout << sum << "\n" << min << "\n";

	return 0;
}