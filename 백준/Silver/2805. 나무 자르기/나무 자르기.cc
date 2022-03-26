// BOJ 2805 나무자르기
// 이진 탐색
// low + high 연산할 때 항상 overflow 의식하기
#include <iostream>

using namespace std;

const int MAXN = 1000010;
int arr[MAXN] = { 0, };

int mmax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N = 0, M = 0;
	cin >> N >> M;

	int maxv = 0;
	for (int i = 0; i < N; i++) {
		int a = 0; cin >> a; // <= 1000000000 = 10억
		arr[i] = a; 
		if (maxv < a) maxv = a;
	}

	long long int low = 0, high = maxv;

	while (low <= high) {
		long long mid = (low + high) >> 1; // 나누기 2
		long long int m = 0;
		for (int i = 0; i < N; i++) {
			m += mmax(0, arr[i] - mid);
		}
		if (m < M) high = mid - 1;
		else low = mid + 1;
	}
	
	long long int ml = 0, mh = 0;
	for (int a : arr) {
		ml += mmax(0, a - low);
		mh += mmax(0, a - high);
	}
	if (ml >= M) cout << low << endl;
	else cout << high << endl;
	
	return 0;
}