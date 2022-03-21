// BOJ 2309 일곱난쟁이
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int h[9] = { 0, };
	for (int i = 0; i < 9; i++) {
		cin >> h[i];
	}
	// 제외될 두 난쟁쓰
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			int sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) continue;
				sum += h[k];
			}
			if (sum == 100) {
				h[i] = 100; h[j] = 100;
				sort(h, h+9);
				for (int k = 0; k < 7; k++)
					cout << h[k] << "\n";

				return 0;
			}
		}
	}

	return 0;
}