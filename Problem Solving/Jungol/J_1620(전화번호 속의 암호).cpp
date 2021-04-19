/*
2021-04-19
J 1620
*/
#include <iostream>
using namespace std;

#define MAX_LEN 110

int main() {
	char str[MAX_LEN] = { 0, };
	int p = 0, m = 0;

	scanf("%s %d %d", str, &p, &m);
	char password[5] = "0000"; int pi = 0;
	int digit = 0; // 5이상이면 에러

	for (int i = 0; i < MAX_LEN; i++) {
		// 반복 종료 조건
		if (!str[i]) break;
		if (digit > 4) { // 에러면 바로 종료
			printf("INPUT ERROR!\n"); return 0;
		}

		if (str[i] == '-') { // 더미 카운트
			m--; digit = 0;
		}
		else if (m == 1 ) {
			// m번째 더미 숫자 추출
			password[pi++] = str[i]; digit++;
		}
		else digit++; // input 에러인지 판단
	}
	
	if (pi <= 3) { // 앞에 0 넣어서 자리수 맞추기
		for (int i = 3; i >= 0; i--) {
			if (pi < 1) password[i] = '0';
			else password[i] = password[--pi];
		}
	}

	for (int pii = 0; pii < 4; pii++) {
		printf("%d", ((password[pii] + p) - '0')%10);
	}
	printf("\n");

	return 0;
}
