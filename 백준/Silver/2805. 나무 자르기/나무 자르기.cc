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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

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

	// while문을 빠져나오면 항상 low = high+1인 상태가 되는데
	// 이때 high 값은 최대 h를 보장한다.
	// while문의 등호가 없다면?? low == high 거나, low == high+1 이라서
	cout << high << endl;
	
	return 0;
}