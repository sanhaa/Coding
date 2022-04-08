// BOJ 2480 주사위 세개
#include <iostream>

using namespace std;

int main() {

	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		cout << 10000 + a * 1000 << endl;
	}
	else if ((a == b && a != c) ) {
		cout << 1000 + a * 100 << endl;
	}
	else if (b == c && a != c) {
		cout << 1000 + b * 100 << endl;
	}
	else if (c == a && a != b) {
		cout << 1000 + c * 100 << endl;
	}
	else {
		if (a > b && a > c) cout << a * 100 << endl;
		else if (b > c && b > a) cout << b * 100 << endl;
		else cout << c * 100 << endl;
	}

	return 0;
}