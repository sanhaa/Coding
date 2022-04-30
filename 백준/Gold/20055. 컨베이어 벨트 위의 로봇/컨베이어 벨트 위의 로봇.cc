// BOJ 20055: 컨테이너 벨트 위의 로봇
#include <iostream>

using namespace std;

const int LEN = 200*2;
int N, K;
int belt[LEN] = { 0, }; // 벨트 내구도
bool robot[LEN] = { 0, };

void cycle() {
	// 1. 벨트 + 로봇 회전
	int temp1 = belt[2*N], temp2 = robot[N];
	for (int i = 2*N; i > 0; i--) {
		belt[i] = belt[i - 1];
		robot[i] = robot[i - 1];
	}
	belt[1] = temp1;
	robot[1] = temp2;

	if (robot[N] == 1) robot[N] = 0;

	// 2. 로봇만 이동
	for (int i = N-1; i > 0; i--) {
		if (!robot[i]) continue;

		int ni = i + 1;
		if (robot[ni] == false && belt[ni] >= 1) {
			robot[ni] = 1; robot[i] = 0; // 로봇 이동
			belt[ni] -= 1; // 내구도 감소
		}
	}
	if (robot[N] == 1) robot[N] = 0;
	
	// 3. 로봇 올리기
	if (belt[1] >= 1) {
		robot[1] = 1;
		belt[1] -= 1;
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	N = 0, K = 0;
	cin >> N >> K;
	for (int i = 1; i <= 2*N; i++) {
		cin >> belt[i];
	}

	int ncycles = 0;
	while (true) {
		cycle();
		ncycles++;

		// 내구도 0인 칸 세기
		int cnt = 0;
		for (int i = 1; i <= 2 * N; i++) {
			if (belt[i] <= 0) cnt++;
		}
		if (cnt >= K) break;
	}
	cout << ncycles << "\n";

	return 0;
}