/*
2021-04-20
J 1761
완전 탐색 (BF)
*/
#include <iostream>

#define MAX_SIZE 10

int main() {
	// 가능한 경우의 수, 123 ~ 987
	char cases[MAX_SIZE * 60][4] = { 0, }; int ci = 0;
	// 모든 경우의 수 setting
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == j) continue;
			for (int k = 1; k <= 9; k++) {
				if (i == k || j == k) continue;
				cases[ci][0] = i + '0';
				cases[ci][1] = j + '0';
				cases[ci][2] = k + '0';
				ci++;
			}
		}
	}

	int output = 504;
	int Q = 0; std::cin >> Q;// 질문 개수
	for (int q = 0; q < Q; q++) {
		char ans[4] = { 0, };
		int S = 0, B = 0; //strike, ball 개수
		scanf("%s %d %d", ans, &S, &B);

		for (int i = 0; i < ci; i++) {
			if (cases[i][0] == 0) continue;
			char* cur = cases[i];
			int s = 0, b = 0;

			// solution: cur, ans, s, b
			for (int c=0;c<3;c++) {
				for (int a = 0; a < 3; a++) {
					if (c == a && cur[c] == ans[a]) s++;
					else if (cur[c] == ans[a]) b++;
				}
			}
			//printf("%s %d %d\n", cur, s, b);
			if (S != s || B != b) { // 안되는 경우 제거
				cases[i][0] = 0; output--;
			}
		}
	}
	
	std::cout << output << std::endl;

	return 0;
}
