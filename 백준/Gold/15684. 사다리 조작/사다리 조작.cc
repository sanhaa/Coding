// BOJ 15684 사다리조작
// 백트래킹할 때 1. vector로 배열 복사해서 함수 인자로 주기 2. 재귀 종료 후 배열 원래 값으로 되돌리기
// 백트래킹할 때 중복 탐색 줄이기 (현재 위치 ~ for문 돌리기) + 놓치는 경우의 수 없게 하기
#include <iostream>
using namespace std;

int N, M, H;
const int MAXH = 40; // <= 30
const int MAXV = 987654321;
int ans = MAXV;

// 모든 세로줄에 대해 i -> i 결과 확인
bool check(bool lines[MAXH][MAXH]) {
	bool res = true; // i -> i 결과 

	for (int st = 1; st <= N; st++) { // start 세로줄
		int cur = st, hori = 1;
		while (hori <= H) {
			if (cur < N && lines[cur][hori]) {
				cur += 1; // 오른쪽 세로줄로 이동
			}
			else if (cur > 1 && lines[cur - 1][hori]) {
				cur -= 1; // 왼쪽 세로줄로 이동
			}
			hori++; 
		}
		//cout << st << " -> " << cur << endl;
		 
		if (st != cur) {
			//cout << st << " -> " << cur << endl;
			res = false;
			break;
		} 
	}

	return res;
}

void set_ladder(int cnt, int verti, int hori, bool lines[MAXH][MAXH]) {
	if (cnt > 3) return;
	
	//cout << cnt << ": " << verti << " " << hori << endl;
	// 사다리 결과 확인
	if (check(lines)) {
		if (ans > cnt) ans = cnt;
 	}

	// 다음 사다리 놓기, 인접하지 않도록
	for (int i = verti; i < N; i++) { // verti ~ N-1
		for (int j = 1; j <= H; j++) { // hori+1 ~ H
			if (lines[i][j] == true) continue;
			// 해당 자리 양 옆에 인접한 사다리
			if (i < N - 1 && lines[i + 1][j] == true) continue;
			if (i > 1 && lines[i - 1][j] == true) continue;

			lines[i][j] = true;
			set_ladder(cnt + 1, i, j, lines);
			lines[i][j] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	N = 0, M = 0, H = 0;
	cin >> N >> M >> H;

	// 사다리 정보
	// lines[i][j] = i~i+1번 세로줄에 j번째 가로 위치에 사다리 여부
	// i: 1~N-1, j:1~H 사용
	bool lines[MAXH][MAXH] = { 0, };

	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		lines[b][a] = true;
	}
	
	//check(lines);
	//cout << "----------------------------\n";

	set_ladder(0, 1, 1, lines);

	
	if (ans == MAXV) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}