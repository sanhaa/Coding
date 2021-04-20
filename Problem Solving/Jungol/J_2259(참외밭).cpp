/*
2021-04-20
J 2259 참외밭
*/
#include <iostream>
using namespace std;

enum direction{
	EAST=1, WEST, SOUTH, NORTH
};

void print_arr(int h[3], int v[3]) {
	for (int i = 0; i < 3; i++) {
		std::cout << h[i] << " ";
	}
	std::cout << endl;
	for (int i = 0; i < 3; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << endl;
}

int main() {

	int K = 0; cin >> K; // 1m^2 넓이에 자라는 참외의 개수
	int max_hi = 0, max_vi = 0; // 최대 가로, 세로 길이
	int h[3] = { 0, };
	int v[3] = { 0, };

	//direction prev;

	int dir, len;
	int max_h = 0, max_v = 0; // 최대 가로, 세로 길이
	int s = 0; // 0 가로 1 세로
	// 6개의 변의 정보
	for (int i = 0; i < 6; i++) {
		cin >> dir >> len;
		
		if (dir == EAST || dir == WEST) { // E W
			h[i / 2] = len;
			if (max_h < len) {
				max_h = len; max_hi = i/2;
			}
		}
		else { // S N
			if (i == 0) s = 1;
			v[i / 2] = len;
			if (max_v < len) {
				max_v = len; max_vi = i/2;
			}
		}
	}

	//print_arr(h, v);
	//cout << max_hi << " " << max_vi << endl;
	// 넓이 구하기
	int S = 0;
	if (max_hi == max_vi) {
		S += h[max_hi] * v[max_vi];
		if(s == 0){
			if (max_hi - 1 < 0) max_hi = 2;
			else max_hi = max_hi - 1;
			S -= h[max_hi] * v[(max_vi + 1) % 3];
		}
		else {
			if (max_vi - 1 < 0) max_vi = 2;
			else max_vi = max_vi - 1;
			S -= h[(max_hi + 1) % 3] * v[max_vi];
		}
	 }
	else {
		S = h[max_hi] * v[max_hi] + h[max_vi] * v[max_vi] - h[max_vi] * v[max_hi];
	}

	std::cout << K * S << endl;

}
