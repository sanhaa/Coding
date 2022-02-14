/*
2021-04-29
J 1701 유전자
DP
*/
#include <iostream>

using namespace std;

#define MAX_LEN 510;

int MAX(int a, int b) {
	return a > b ? a : b;
}

char DNA[510] = { 0, };
int d [510][510] = { 0, }; // d[i][j] : i 부터 j 까지 KOI

int main() {
	scanf("%s", DNA);
	int len = -1;
	while (DNA[++len]);
	
	for (int j = 1; j < len; j++) {

		for (int i = j - 1; i >= 0; i--) {
			// 조건 1 체크
			if ((DNA[i] == 'a' && DNA[j] == 't') || (DNA[i] == 'g' && DNA[j] == 'c')) {
				d[i][j] = d[i + 1][j - 1] + 2;
			}

			// 조건 2 
			for (int k = i + 1; k < j; k++) {
				d[i][j] = MAX(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	//for (int i = 0; i < len; i++) {
	//	for (int j = 0; j < len; j++) {
	//		cout << d[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << d[0][len - 1] << endl;

	return 0;
}
