// BOJ 1389: 케빈 베이컨의 6단계 법칙
// 케빈 베이컨의 수가 가장 작은 사람, 여러 명일 경우 번호가 가장 작은 사람
// 1 - 3
// 1 - 4
// 2 - 3
// 3 - 4
// 4 - 5
// 2 -> (3) -> 1 = 1=2단계
// 2 -> 3 = 1단계
// 2 -> 3 -> 4 = 2단계
// 2 -> 3 -> 4 -> 5 = 3단계
// 2의 케빈 베이컨 수 = 2+1+2+3 = 8
#include <iostream>

using namespace std;

const int MAXN = 110;
int N = 0, M = 0;
int arr[MAXN][MAXN] = { 0, };

// n의 케빈 베이컨 수 구하기
// DFS 
int kevin_of(int n) {
	int conn[MAXN] = { 0, }; // conn[i] = n과 i가 연결되는 최소 단계 수
	pair<int, int> st[MAXN]; int top = -1;
	st[++top] = make_pair(n, 0); // 번호, depth

	while (top >= 0) {
		pair<int, int> cur = st[top--];
		
		for (int i = 1; i <= N; i++) {
			if (i == n) continue;
			
			if (arr[cur.first][i] == 1) {
				if (conn[i] == 0 || conn[i] > cur.second + 1){
					st[++top] = make_pair(i, cur.second + 1);
					conn[i] = cur.second + 1;
				}
			}
		}
	}

	int kevin = 0;
	for (int i = 1; i <= N; i++) {
		kevin += conn[i];
	}
	return kevin;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a = 0, b = 0; cin >> a >> b;
		arr[a][b] = 1; arr[b][a] = 1;
	}

	int min_kevin = 987654321, ans=0;
	for (int i = 1; i <= N; i++) {
		int ret = kevin_of(i);
		if (min_kevin > ret) {
			min_kevin = ret;
			ans = i;
		}
	}
	cout << ans << "\n";

	return 0;
}