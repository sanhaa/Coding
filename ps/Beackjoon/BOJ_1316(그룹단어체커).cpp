// BOJ 1316 그룹단어체커
#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 110;

int main() {
	int N = 0;
	char words[MAX_N][MAX_N];
	cin >> N;

	for (int n = 0; n < N; n++) {

		cin >> words[n];
	}

	int cnt_group = 0;

	for (int n = 0; n < N; n++) {
		string word = words[n];
		bool is_group = true;
		bool is_contd = false; char prev = ' ';
		bool check[26] = { 0, };
		
		for (char c : word) {
			if (c=='\0') break; 
			if (prev == c) is_contd = true;
			else is_contd = false;

			if (!is_contd) {
				if (check[c - 97]) {
					is_group = false; break;
				}
				else {
					check[c - 97] = true;
				}
			}
			prev = c;
		}
		if (is_group) cnt_group += 1;
	}

	cout << cnt_group << endl;

	return 0;
}
