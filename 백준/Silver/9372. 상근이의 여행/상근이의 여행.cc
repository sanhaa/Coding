// BOJ 9372 상근이의 여행
#include <iostream>

using namespace std;

const int MAXN = 1010;
const int MAXM = 10010;

bool A[MAXN][MAXN] = { 0, };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T = 0, N = 0, M = 0;
	cin >> T;
	while (T--) {
		N = 0, M = 0;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a = 0, b = 0;
			cin >> a >> b;
			A[a][b] = 1;
			A[b][a] = 1;
		}
		cout << N - 1 << "\n";
	}

	return 0;
}