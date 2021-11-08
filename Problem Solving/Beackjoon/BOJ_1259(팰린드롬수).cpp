#include <iostream>

using namespace std;

const int MAX_LEN = 6;

int main() {
	char str[MAX_LEN];

	while (cin>>str) {
		if (str[0] == '0') break;

		// get length
		int len = -1;
		while (str[++len]) {}

		// check 
		bool flag = 1;
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - 1- i]) {
				cout << "no" << endl;
				flag = 0; break;
			}
		}
		if (flag) cout << "yes" << endl;
	}

	return 0;
}
