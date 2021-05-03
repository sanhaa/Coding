/*
2021-05-03
기출문제 : 개미탈출
시뮬레이션, 자료구조
*/
#include <iostream>
#include <map>

using namespace std;

typedef pair<int, int> PII;

enum DIR {
	UP = 1, DOWN, LEFT, RIGHT
};

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

const int MAX_N = 5010;
int M, N, K;
int ans_sec, ans_num;
int out_cnt; // 탈출한 개미 수

int main() {
	int tc = 0; scanf("%d", &tc);

	/*  test case 반복  */
	for (int t = 0; t < tc; t++) {

		// 변수 초기화
		M = 0; N = 0; K = 0;
		ans_sec = 0; ans_num = 0; out_cnt = 0;

		// key : pair(x, y)
		// value : pair(idx, dir)
		// 묶어서 구조체 선언해도 되지만 충돌 여부 판단을 빠르게 하기 위해 key 값 설정
		map<PII, PII> m; 

		/*  input  */
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 1; i <= N; i++) { // 1 ~ N 사용
			int x, y, dir;
			cin >> x >> y >> dir;
			m.insert(make_pair(x, y), make_pair(i, dir));
		}

		while (out_cnt <= K) {
			ans_sec++;

			for (auto iter = m.begin(); iter != m.end(); iter++) {
				// MOVE
				int dir = (*iter).second.second;
				int x = m.at((*iter).first).first + dx[dir]; // new x
				int y = m.at((*iter).first).second + dy[dir];
				int idx = (*iter).second.first;
				m.erase((*iter).first); // key는 변경 못하니까 지우고 다시 만들어야 하는데 이게 맞나

				if (m.size() == 0) break;

				if (x == M) {
					// 탈출
					out_cnt++;
					// 동시에 탈출한 개미 있으면 그 중에 y좌표 낮은 걸로 출력
					if (out_cnt == K) {
						ans_num = idx; 
					}
					continue;
				}
				if (x >= M || y >= M || x <= 0 || y <= 0) {
					// 범위 벗어나면
					continue;
				}

				// 새로운 위치, 업데이트 된 방향(필요시)으로 ant insert
				PII new_xy = make_pair(x, y);
				int new_dir = 0;
				// 새로 움직인 위치에서 충돌이 발생하는지?
				auto it = m.find(new_xy);
				if (it != m.end()) {
					// 충돌발생, 방향 수정
					new_dir = (*it).second.second;
					(*it).second.second = dir;
				}

				m.insert(new_xy, make_pair(idx, new_dir));
			}

		}

		printf("#%d %d %d\n", t + 1, ans_sec, ans_num);
	}

	return 0;
}
