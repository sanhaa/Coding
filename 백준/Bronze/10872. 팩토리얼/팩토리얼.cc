// BOJ 10872 팩토리얼
#include <iostream>

using namespace std;

int fac(int n) {
	if (n <= 1) return 1;
	else return n * fac(n - 1);
}

int main() {
	int N = 0; cin >> N;
	cout << fac(N) << endl;

	return 0;
}