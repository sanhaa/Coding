// BOJ 1676 팩토리얼 0의 개수
// long long int로 커버가 되나?
#include <iostream>
using namespace std;

int main() {

	int N = 0; cin >> N;

	int twos = 0, fives = 0; // 2, 5 소인수 개수
	for (int n = 1; n <= N; n++) {
		int tn = n;
		while (tn > 1) {
			if (tn % 2 == 0) {
				twos++;
				tn /= 2;
			}
			else break;
		}
		tn = n;
		while (tn > 1) {
			if (tn % 5 == 0) {
				fives++;
				tn /= 5;
			}
			else break;
		}
	}

	cout << (twos < fives ? twos : fives) << "\n";

	return 0;
}