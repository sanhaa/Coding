// BOJ 1074: Z
// 분할정복, 재귀
#include <iostream>
using namespace std;

int N = 0, r = 0, c = 0;
int ans = 0;
// size*size 사분면, start: 좌상단 좌표
void solve(int size, pair<int, int> start) {

	if (size == 1) return;

	int half = size >> 1;
	int mid_r = start.first + half, mid_c = start.second + half;
	if (r < mid_r) {
		if (c < mid_c) solve(half, start);
		else {
			ans += half * half;
			solve(half, make_pair(start.first, mid_c));
		}
	}
	else {
		if (c < mid_c) {
			ans += half * half * 2;
			solve(half, make_pair(mid_r, start.second));
		}
		else {
			ans += half * half * 3;
			solve(half, make_pair(mid_r, mid_c));
		}
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> r >> c;
	solve((1 << N), make_pair(0, 0));  // 2^N
	cout << ans << "\n";

	return 0;
}