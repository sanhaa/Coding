// BOJ 9252 LCS2
// 알고리즘: DP
// 특징: 최장 공통 부분 수열 길이만 구하는게 아니라 그 수열도 출력해야 함.
// string 라이브러리 사용/사용X
#include <iostream>
#include <string>
using namespace std;

const int LEN = 1010;
string X, Y;
// LCS 문자열 저장 배열
string LCS[LEN][LEN]; // LCS[i][j]= X[i], Y[j]까지의 LCS

// 길이가 더 긴 문자열을 반환
string mmax_str(string a, string b) {
	return a.length() > b.length() ? a : b;
}

int main() {
	cin >> X >> Y;
	int N = X.length(), M = Y.length();

	// LCS 구하기 (문자열)
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (X[i-1] == Y[j-1]) {
				LCS[i][j] = mmax_str(LCS[i][j-1], LCS[i-1][j-1]+X[i-1]);
			}
			else {
				LCS[i][j] = mmax_str(LCS[i-1][j], LCS[i][j - 1]);
			}
		}
	}

	// LCS 길이
	int len = LCS[N][M].length();
	cout << len << endl;

	// LCS 출력
	cout << LCS[N][M] << endl;

	return 0;
}
