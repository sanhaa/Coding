#include <iostream>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for (int t = 1;t <= tc;t++) {
		char str[1001] = { 0, };
		scanf("%s", str);

		int len = 0;
		while (str[len]) len++;

		// reverse
		for (int i = 0;i < len/2;i++) {
			char tmp = str[i];
			str[i] = str[len - 1 - i];
			str[len - 1 - i] = tmp;
		}

		// change character
		for (int i = 0;i < len;i++) {
			switch (str[i]) {
			case 'p':	str[i] = 'q'; break;
			case 'q':	str[i] = 'p'; break;
			case 'b': 	str[i] = 'd'; break;
			case 'd': 	str[i] = 'b'; break;
			}
		}

		printf("#%d %s\n", t, str);
	}

	return 0;
}
