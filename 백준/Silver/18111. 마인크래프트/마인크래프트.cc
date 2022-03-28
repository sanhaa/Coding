// BOJ 18111 마인크래프트
// 구현, BF
#include <iostream>

using namespace std;

const int MAXN = 510;
int arr[MAXN][MAXN] = { 0, };
int N = 0, M = 0;
int min_time = 987654321, max_height=0;

void calculate_time(int h, int B) {
	int time = 0;
	for (int i = 0; i < N; i++) {
		if (time > min_time) return;

		for (int j = 0; j < M; j++) {
			int diff = h - arr[i][j];

			if (diff > 0) { // h가 더 큰 경우 set block
				time += diff;
			}
			else if (diff < 0) { // h가 더 작은 경우 remove block
				time += 2 * (-diff);
			}
			B -= (diff); // 인벤토리 블록 추가, 사용 반영
		}
	}
	if (B < 0) return;
	if (min_time > time) {
		min_time = time;
		max_height = h;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int B = 0, h = 0;
	cin >> M >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a = 0; cin >> a;
			arr[i][j] = a;
			if (h < a) h = a;
		}
	}

	while (h>=0) { // 최대 높이 ~ 0까지 time 계산
		calculate_time(h, B);
		h--;
	}

	cout << min_time << " " << max_height << "\n";

	return 0;
}