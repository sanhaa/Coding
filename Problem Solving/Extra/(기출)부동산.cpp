/*
기출 : 부동산
- 이차원 배열의 부분합 구하기
누적합 배열 설정 -> O(N*N) 으로 단축
시작 위치, 끝위치를 1 + M*N 으로 표현
최대 시세차익이 여러개 일 때 처리 -> 안해도 되는 구조인가?
*/
#include <iostream>

using namespace std;

#define MAX_SIZE 310

int N = 0, M = 0;
int arr[MAX_SIZE][MAX_SIZE] = { 0, }; // 원본 배열
int S[MAX_SIZE][MAX_SIZE] = { 0, }; // 누적합

struct POS {
	int num = 0;
	int row = 0;
	int col = 0;

	void num2pos() {
		row = (num - 1) / M + 1;
		col = (num - 1) % M + 1;
	}
	void pos2num() {
		num = (row - 1) * M + 1 + (col-1);
	}
};

pair<int, int> num2pos(int num){
	int row = (num - 1) / M + 1;
	int col = (num - 1) % M + 1;

	return make_pair(row, col);
}

int sub_sum(POS start_p, POS end_p) {

	int ret = S[end_p.row][end_p.col] - S[start_p.row - 1][end_p.col]
		- S[end_p.row][start_p.col - 1] + S[start_p.row - 1][start_p.col - 1];

	return ret;
}

int main() {
	int T = 0; cin >> T;
	for (int t = 1; t <= T; t++) {
		// 초기화
		int L = 0;

		cin >> N >> M >> L;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> arr[i][j];
				arr[i][j] -= L; // 시세 차익 저장

				S[i][j] = S[i][j - 1] + arr[i][j]; // 가로 누적합
			}
		}

		// set S row 방향 누적합
		for (int j = 1; j <= M; j++) {
			for (int i = 1; i <= N; i++) {
				S[i][j] = S[i - 1][j] + S[i][j];
			}
		}

		int max_profit = 0; // 최대 시세 차익
		int max_s = 0, max_e = 0; // 시세차익이 최대일 때의 start, end 위치

		// 최대 부분합 구하기
		for (int start = 1; start <= N * M; start++) {
			for (int end = 1; end <= N * M; end++) {
				POS start_p, end_p;

				start_p.num = start; end_p.num = end;
				start_p.num2pos(); 	end_p.num2pos(); 

				// start가 end보다 왼쪽에 있지 않으면
				if (start_p.row > end_p.row || start_p.col > end_p.col) continue;

				int ret = sub_sum(start_p, end_p); // start ~ end 부분합
				if (max_profit < ret && ret > 0) {
					max_profit = ret;
					max_s = start; max_e = end;
				}
				// 최대 시세 차익이 동일 할 때 땅 매입가가 가장 적도록 선택해야 한다.
			}
		}

		// 땅 매입가
		pair<int, int> start = num2pos(max_s);
		pair<int, int> end = num2pos(max_e);
		int land_buy = (end.first - start.first + 1) * (end.second - start.second + 1) * L;

		cout << "#" << t << " " << max_profit << " " << (max_profit > 0 ? land_buy : 0) << endl;
	}
	return 0;
}
