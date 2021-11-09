// BOJ 10757 큰 수 A+B
// string

#include <iostream>
#include <string>

using namespace std;

//const int MAX_LEN = 

int main() {

	string A, B, res;
	cin >> A >> B;

	int aidx = A.length() - 1;
	int bidx = B.length() - 1;

	bool carry = false;

	while (aidx >= 0 || bidx >= 0) {
		int ai = 0, bi = 0; // 한자리씩 int로 변환
		if (aidx >= 0) ai = A[aidx] - '0';

		if (bidx >= 0) bi = B[bidx] - '0';

		int cal = ai + bi + carry; // 올림수 처리
		if (cal >= 10) carry = true;
		else carry = false;

		cal %= 10;
		res.append(to_string(cal));

		aidx--; bidx--;
	}

	if (carry) res.append("1");

	// res 반대로 출력하기 
	for (int i = res.length() - 1; i >= 0; i--) {
		cout << res[i];
	}
	cout << endl;

	return 0;
}
