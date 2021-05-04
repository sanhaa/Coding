
/*
2021-05-03
기출문제 : 개미탈출
시뮬레이션, 자료구조

- 동시 탈출 처리
- 충돌 판단 개선
- 방향4에 대해서만 검사 (방4 x좌표로 정렬해서 기준으로 움직이다가 충돌 고려해서 기준 변경)
*/
#include <iostream>
#include <map>

using namespace std;

enum DIR {
	UP = 1, DOWN, LEFT, RIGHT
};

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

const int MAX_N = 5010;
int M, N, K;
int out_cnt; // 탈출한 개미 수
int active_cnt; // 움직일 수 있는 개미 수

struct ANSWER {
	int sec = 0;
	int num = 0; // 개미 번호
	
}answer;

struct ANT {
	int idx = 0;
	int x = 0;
	int y = 0;
	int dir = 0; // 방향 1 ~ 4
	bool active = 0; // 움직일 필요가 있는 개미면 1
	int sec = 0; // ?
};

int main() {

	freopen("input.txt", "r", stdin);

	int tc = 0; scanf("%d", &tc);

	/*  test case 반복  */
	for (int t = 0; t < tc; t++) {

		// 변수 초기화
		M = 0; N = 0; K = 0;
		answer.sec = 0; answer.num = 0; out_cnt = 0; active_cnt = N;

		ANT ant[MAX_N];
		map<int, map<int, ANT>> m;

		/*  input  */
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 1; i <= N; i++) { // 1 ~ N 사용
			cin >> ant[i].x >> ant[i].y >> ant[i].dir;
		}

		while (out_cnt <= K && active_cnt>=0) {
			m.clear();
			// 개미 1 ~ N 까지 MOVE
			for (int i = 1; i <= N; i++) {
				cout << i << " th move : " << ant[i].x << " " << ant[i].y << endl;

				if (ant[i].active == 0) continue;

				// MOVE
				ant[i].x += dx[ant[i].dir];
				ant[i].y += dy[ant[i].dir];

				// 탈출 여부
				if (ant[i].x >= M) {
					ant[i].active = 0; active_cnt--;
					
					if (out_cnt == K && answer.sec == ant[i].sec ) {
						// 동시 탈출 처리
						if (ant[answer.num].y > ant[i].y) {
							answer.num = i; // y값이 더 작으면 num update
						}
						
					}
					else {
						out_cnt++; 
					}
				}
				// map 범위 체크
				else if (ant[i].x >= M || ant[i].y >= M || ant[i].x <= 0 || ant[i].y <= 0) {
					ant[i].active = 0; active_cnt--;
				}

				// 충돌 체크 및 처리
				auto iterx = m.find(ant[i].x);
				auto itery = m.at(ant[i].x).find(ant[i].y);
				if (iterx != m.end() && itery != m.at(ant[i].y).end()) { // 충돌 발생
					// 충돌 처리, dir swap
					int tmp = ant[i].dir;
					ant[i].dir = (*itery).second.dir;
					m.at(ant[i].x).at(ant[i].y).dir = tmp;
				}
			}
		}

		printf("#%d %d %d\n", t + 1, answer.sec, answer.num);
	}

	return 0;
}
