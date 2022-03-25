// BOJ 11728 배열합치기
// 정렬되어 있는 배열 A, B 합치기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
int  A[MAXN] = { 0, }, B[MAXN] = { 0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int j = 0; j < M; j++) {
		cin >> B[j];
	}
	
	int a = 0, b = 0;

	while (a < N || b < M) {
		
		if (a >= N) cout << B[b++] << " ";
		else if (b >= M) cout << A[a++] << " ";

		else {
			if (A[a] < B[b]) {
				cout << A[a++] << " ";
			}
			else {
				cout << B[b++] << " ";
			}
		}
	}

	return 0;
}