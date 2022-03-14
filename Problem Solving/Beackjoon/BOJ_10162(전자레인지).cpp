// 프로그래머스 > 그리디 > 체육복 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int times[3] = { 300, 60, 10 };
	int ans[3] = { 0, };

	for (int i = 0; i < 3; i++) {
		ans[i] = T / times[i];
		T %= times[i];
	}

	if (T != 0) cout << -1 << endl;
	else {
		for (int a : ans) {
			cout << a << endl;
		}
	}

	return 0;
}
