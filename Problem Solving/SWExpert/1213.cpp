// SWE 1213
#include <iostream>

using namespace std;
const char sharp = '#';

int len_of(char* s) {
	int len = 0;
	while (s[len])
		len++;
	return len;
}

int main() {
	int T = 10;

	freopen("1213_input.txt", "r", stdin);

	for (int t = 1;t <= T;t++) {
		cin >> t;

		int ans = 0; // 문자열 개수
		char statement[1001] = { 0, };
		char key[11] = { 0, };

		scanf("%s %s", key, statement);

		int key_len = len_of(key);
		int state_len = len_of(statement);

		int i = 0; // 원본 문자열 인덱스
		int j = 0; // 찾을 문자열 인덱스

		while (statement[i]) {
			while (key[j] && (statement[i] == key[j])) {
				i += 1; j += 1;
			}
			if (j == key_len) { // key 문자열 끝까지 일치
				ans += 1;
			}
			i -= j;
			j = 0;
			i++;
		}

		cout << sharp << t << " " << ans << endl;
	}
}
