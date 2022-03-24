// S 1264 dl 이미지 유사도 검사
#include <iostream>
using namespace std;

const int MAX_N = 510;
int LCS[MAX_N][MAX_N] = { 0, };
char X[MAX_N] = { 0, };
char Y[MAX_N] = { 0, };

int mmax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	freopen("input.txt", "r", stdin);

	int tc = 0; scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int N = 0; scanf("%d", &N);//<= 500

		// init
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) LCS[i][j] = 0;

			X[i] = 0; Y[i] = 0;
		}

		scanf(" %s", X);
		scanf(" %s", Y);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 각각 i, j 길이보다 LCA[i][j] 값이 클 수 없고 탐색할 필요 없다
				if (X[i-1] == Y[j-1]) // 0 ~ N 에 저장되어 있어서
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else {
					if (LCS[i][j - 1] >= j || LCS[i][j - 1] >= i) {
						LCS[i][j] = LCS[i][j - 1];
						continue;
					}
					LCS[i][j] = mmax(LCS[i - 1][j], LCS[i][j - 1]);
				}
			}
		}

		int ans = LCS[N][N];
		printf("#%d %.2f\n", t, (ans / (float)N) * 100);

	}

	return 0;
}
