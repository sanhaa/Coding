// BOJ 1750 암호 만들기
// BF
#include <iostream>

using namespace std;

const int MAXC = 15;
int L = 0, C = 0;
char alph[MAXC+1] = { 0, };

void backtrack(int idx, int len, char* pwd) {
	if (len == L) {
		// 모음 1개이상, 자음 2개 이상 검사
		int v = 0;
		for (int i = 0; i < len;i++) {
			char c = pwd[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v++;
		}
		if (v < 1 || (len - v) < 2) return;
		// 정답 출력
		cout << pwd << "\n";
		return;
	}
	// idx >= C ??
	for (int i = idx + 1; i < C; i++) {
		pwd[len] = alph[i];
		backtrack(i, len + 1, pwd);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	/* INPUT */
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alph[i];
	}
	/* SORT */
	for (int i = 0; i < C; i++) {
		char mv = alph[i]; // min val, 
		int mi = i; // min idx
		for (int j = i + 1; j < C; j++) {
			if (alph[j] < mv) {
				mv = alph[j]; mi = j;
			}
		}
		// swap
		char c = alph[i];
		alph[i] = mv;
		alph[mi] = c;
	}

	/* C개 중 L개 뽑기 */
	char pwd[MAXC] = { 0, };
	for (int i = 0; i < C; i++) {
		int len = 0;
		pwd[len] = alph[i];
		backtrack(i, 1, pwd);
	}

	return 0;
}