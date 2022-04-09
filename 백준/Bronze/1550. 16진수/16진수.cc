// BOJ 1550 16진수
#include <iostream>
#include <string>
using namespace std;

int main() {
	string num;
	cin >> num;
	int ans = 0, multi = 1;
	for (int i = num.length() - 1; i >= 0; i--) {
		int n = 0;
		if (num[i] >= 'A') {
			n = num[i] - 'A' + 10;
		}
		else n = num[i] - '0';
		ans += n * multi;
		multi *= 16;
	}
	cout << ans << "\n";
	return 0;
}