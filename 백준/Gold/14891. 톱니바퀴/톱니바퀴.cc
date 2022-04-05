// BOJ 14891: 톱니바퀴
#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[5][8] = { 0, }; // 톱니바퀴 정보
	int dir12[5] = { 0, }; // 톱니바퀴 12시방향 인덱스

	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			if (c == '1') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	int K = 0; cin >> K;
	while (K--) {
		int num = 0, dir = 0;
		cin >> num >> dir;

		pair<int, int> que[10];
		int front = -1, rear = -1;
		que[++rear] = make_pair(num, dir);

		int rotate[5] = { 0, }; // 동시에 돌아야 할 톱니바퀴 [번호] = 방향
		rotate[num] = dir;

		while (front < rear) {
			pair<int, int> cur = que[++front];
			int cur_n = cur.first, left = cur_n-1, right = cur_n+1;
			int cur_d = cur.second;

			if (left >= 1 && rotate[left]==0) {
				if (arr[cur_n][(dir12[cur_n] + 6) % 8] != arr[left][(dir12[left] + 2) % 8]) {
					rotate[left] = -cur_d; // 반대방향
					que[++rear] = make_pair(left, -cur_d);
				}
			}
			if (right <= 4 && rotate[right] == 0) {
				if (arr[cur_n][(dir12[cur_n] + 2) % 8] != arr[right][(dir12[right] + 6) % 8]) {
					rotate[right] = -cur_d;
					que[++rear] = make_pair(right, -cur_d);
				}
			}
		}

		// rotate[] 표시대로 돌리기
		for (int n = 1; n <= 4; n++) {
			if (rotate[n] == 0) continue;
			dir12[n] = (dir12[n] + 8 - rotate[n]) % 8;
		}
	}
	int ans = 0, two=1;
	for (int n = 1; n <= 4; n++) {
		ans += arr[n][dir12[n]] * (two);
		two *= 2;
	}
	cout << ans << "\n";

	return 0;
}