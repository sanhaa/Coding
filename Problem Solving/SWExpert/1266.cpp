#include <iostream>
#include <cmath>
using namespace std;

int prime_nums[7] = { 2, 3, 5, 7, 11, 13, 17 };

// 조합의 개수를 반환한다.
int combinations(int n, int r) {
	if (r == 1) 
		return n;
	else if (r == n)
		return 1;
	else 
		return combinations(n - 1, r - 1) + combinations(n - 1, r);
}

// prob 확률에 대해서 완제품이 소수 pn일 확률
double probability_of(int pn, double prob) {
	//  18Cpn * prob^pn * (1-prob)^(1-pn)
	// 조합
	int C = combinations(18, pn);
	double ret = C * pow(prob, pn) * pow(1 - prob, 18 - pn);
	return ret;
}

int main() {
	//freopen("1266_input.txt", "r", stdin);

	int tc = 0;
	cin >> tc;

	// test case 개수만큼 반복
	for (int t = 1;t <= tc;t++) {
		double ans = 0;

		// input
		double A_prob = 0, B_prob = 0; // 0 ~ 100 정수
		cin >> A_prob >> B_prob; 

		A_prob /= 100.0; // 0~100 -> 0 ~ 1
		B_prob /= 100.0;

		double A_sum = 0.0, B_sum = 0.0; // A, B 각각 완제품이 소수일 확률
		for (int pn : prime_nums) {
			A_sum += probability_of(pn, A_prob);
			B_sum += probability_of(pn, B_prob);
		}

		// 둘 중 한명 이상의 완제품 개수가 소수일 확률은
		// 전체확률(1) - (A 완제품이 소수가 아닐 확률)*(B)
		ans = 1 - (1 - A_sum) * (1 - B_sum);

		printf("#%d %.6lf\n", t, ans);
	}
}
