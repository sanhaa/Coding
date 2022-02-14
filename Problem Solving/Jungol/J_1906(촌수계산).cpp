/*
2021-04-23
J 1906 촌수계산
알고리즘: LCA 변형
*/
#include <iostream>
using namespace std;

#define MAX_N 110

int N = 0; int M = 0;
int parent[MAX_N] = { 0, };

int height_of(int n) {
	int h = 0;
	while (n >= 1) {
		n = parent[n]; h++;
	}
	
	return h-1;
}

int solution(int n, int m) {

	int nh = height_of(n);
	int mh = height_of(m);

	int nn = 0, mm = 0; // 각각 공통조상까지의 거리 카운트

	// 높이 맞춰주기
	if (nh < mh) {
		while (nh != mh) {
			mh--; mm++;
			m = parent[m];
		}
	}
	else if (nh > mh) {
		while (nh != mh) {
			nh--; nn++;
			n = parent[n];
		}
	}

	while (n != m && (n > 0 && m > 0)) {
		n = parent[n];
		m = parent[m];
		nn++; mm++;
	}
	
	if (n == 0 && m == 0) return -1;
	else return nn + mm;
}

int main() {

	cin >> N;

	int n = 0, m = 0;
	cin >> n >> m;

	cin >> M;
	for (int i = 0;i < M;i++) {
		int p = 0, c = 0;
		cin >> p >> c;
		parent[c] = p;
	}
	
	int ans = solution(n, m);
	cout << ans << endl;

	return 0;
}
