// BOJ 2525 오븐 시계
#include <iostream>

using namespace std;

int main() {
	int A = 0, B = 0, C = 0;
	cin >> A >> B >> C;

	B = B + C;
	if (B >= 60) {
		A += B/60;
		B %= 60;
	}
	if (A >= 24) {
		A = A-24;
	}
	cout << A << " " << B << endl;
	return 0;
}