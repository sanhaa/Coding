// BOJ 4673 셀프 넘버
// 함수, 구현, 수학
// 이중 loop로 1~10000 중에 self_num 아닌거 골라내기

#include <iostream>

using namespace std;

const int mmax = 10001;

int digit_sum(int n) {
	int ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	bool is_selfn[mmax] = { false, };
	for (int st = 1; st < mmax; st++) {
		int dn = st + digit_sum(st); // next dn

		while (dn < mmax) {
			if (is_selfn[dn]) break; // 이미 dn이 self num이면 이후 계산도 끝났을 것이라 판단
			is_selfn[dn] = true;
			dn = dn + digit_sum(dn); // next dn
		}
	}

	// print out
	for (int i = 1; i < mmax; i++) {
		if (!is_selfn[i]) cout << i << endl;
	}

	return 0;
}

 //너무 어렵게 생각했나 ? 다른 효율적 방법은 없을까