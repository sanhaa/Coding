// BOJ 1065 한수

#include <iostream>

using namespace std;

bool is_hannum(int n) {
	if (n == 1000) return false;

	// 등차 수열 특징: (수가 세 개일 때)양쪽의 수를 더함 == 가운데수 * 2
	if ((n / 100) % 10 + (n % 10) == ((n / 10) % 10)*2) return true;
	else return false;
}

int main() {
	int N = 0; cin >> N;
	int ans = 0;

	if (N < 100) ans = N;
	else { // N이 세자리수
		ans = 99; // 두자리 수는 모두 한수
		for (int i = 100; i <= N; i++) {
			if (is_hannum(i)) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}