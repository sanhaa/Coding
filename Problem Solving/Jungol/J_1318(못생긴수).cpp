/*
2021-04-30
J 1318 못생긴 수
DP
*/
#include <iostream>

using namespace std;

#define MAX_N 2000

int mmin(int a, int b) {
	return a < b ? a : b;
}

int mmin(int a, int b, int c) {
	return mmin(mmin(a, b), c);
}

enum MULT {
	TWO = 2, THREE = 3, FIVE = 5
};

int main() {

	int n = 0;
	// DP 배열: d[i] = i번째 못생긴 수
	int d[MAX_N] = { 0, }; 

	d[1] = 1;
	int base2 = TWO, base3 = THREE, base5 = FIVE;
	int idx2 = 1, idx3 = 1, idx5 = 1;

	while (cin >> n) {
		if (!n) break; // 입력 종료
		//if (d[n]) break; 
		
		for (int i = 1;i <= n;i++) {
			if (d[i]) continue;

			// 다음 못생긴 수 중에서 제일 작은 값
			d[i] = mmin(base2, base3, base5);

			// 못생긴 수로 d[i]에 기록되었다면 다음 못생긴 수 구하려고
			if (d[i] == base2) {
				base2 = d[++idx2] * TWO;
			}
			if (d[i] == base3) {
				base3 = d[++idx3] * THREE;
			}
			if (d[i] == base5) {
				base5 = d[++idx5] * FIVE;
			}
		}

		cout << d[n] << endl; // n번째 못생긴 수
	}

	return 0;
}
