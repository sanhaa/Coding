// MCM (Matrix Chain Multiplication)
// 행렬 곱 연산 최소 구하기, DP 기반
#include <iostream>
using namespace std;

#define MAX_SIZE 30 // 최대 행렬 개수
#define INF 987654321
const char sharp = '#';

int M[MAX_SIZE][MAX_SIZE] = { 0, };
int d[MAX_SIZE] = { 0, }; // 행렬 개수 

int mmin(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int tc = 1; /* cin >> tc;*/
	// A: 3*4 B: 2*3 C: 4*5

	for (int t = 1; t <= tc; t++) {
		int N = 4; /*cin >> N;*/
		// B * A * C
		d[0] = 20; d[1] = 1; d[2] = 30; d[3] = 10; d[4] = 10;

		for (int r = 2; r <= N; r++) {
			for (int i = 1; i <= N - r + 1; i++) {
				int j = i + r - 1;
				M[i][j] = INF;
				for (int k = i; k < j; k++) {
					M[i][j] = mmin(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
				}
			}
		}
		// print Matrix M
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++) {
				cout << M[i][j] << "  ";
			}
			cout << endl;
		}
    // 답, 최소 곱 연산 횟수
		cout << sharp << t << " " << M[1][N] << endl;
	}

	return 0;  
}
