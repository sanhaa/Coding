// BOJ 1541 잃어버린괄호
// - 연산자와 - 연산자 사이는 모두 묶어서 연산
#include <iostream>
#include <string>
using namespace std;


int main() {
	string s;
	cin >> s;

	int i = 0, res = 0;
	bool minus = false; // 이전 부호가 -인지

	while (i < s.length()) {
		string num = ""; // cur number
		while (true) {
			num += s[i];
			i++;
			if (i >= s.length()) break;
			if (s[i] == '+' || s[i] == '-') break;
		}

		if (!minus) res += stoi(num);
		else res -= stoi(num);

		if (s[i] == '-' || (s[i] == '+' && minus)) {
			minus = true;
		}
		i++;
	}
	cout << res << endl;

	return 0;
}