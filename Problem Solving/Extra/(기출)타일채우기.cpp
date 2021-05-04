/*
2021-05-04
기출: 타일 채우기
알고리즘: DP
*/
#include <iostream>
#include <ctime>

using namespace std;

#define MAX_N 1000010

// d[i] = 너비가 i일 때 빈공간 없이 꽉 채우는 경우의 수
int d[MAX_N] = { 0, }; 
int N = 0;
int divisor = 100000007;

// ~idx까지 d채우기
void set_d(int idx) {
	int i = 0;

	while (i++ != idx) {
		if (d[i] != 0 || i&1) continue;

		for (int j = 0; j < i; j += 2) {
			d[i] += d[j]; // 0, 2, .... i-2
		}
		d[i] *= 2;
		d[i] += d[i - 2];
	}
}

int main() {
	time_t start, end;
	start = clock();

	int T = 0; cin >> T; // Test case
	d[0] = 1;

	for (int t = 1; t <= T; t++) {
		int ans = 0; int N = 0; // 너비
		int x0, y0; // empty space x, y
		cin >> N >> x0 >> y0;

		set_d(N);

		if ((x0 + y0) & 1 == 1) ans = 0; // x0, y0의 홀짝이 다르면 답 없음
		else {
			// type 1 : y = 1 or 3
			if (y0 != 2) {
				for (int j = 0; j <= N - x0; j += 2) {
					ans += d[x0-1] * d[j] % divisor;
				}
				for (int i = x0-3; i >=0 ; i-=2) {
					ans += d[N - x0] * d[i] % divisor;
				}
			}
			//type 2 : y = 2
			else {
				for (int j = 0; j < N - x0; j += 2) {
					for (int i = x0 - 2; i >= 0; i -= 2) {
						ans += d[j] * d[i] % divisor;
					}
				}
				ans *= 2 % divisor;
			}
		}
		//for (int i = 0; i <= N; i++) {
		//	cout << d[i] << " ";
		//}
		//cout << endl;
		cout << "#" << t<<" " << ans % divisor << endl;
	}
	end = clock();

	printf("%f\n", (double)(end - start));

	return 0;
}
