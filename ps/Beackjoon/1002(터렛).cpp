// BOJ 1002 터렛
// 수학, 기하학

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int T = 0; cin >> T;
	while (T--) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		int r1 = 0, r2 = 0;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (r1 > r2) swap(r2, r1);
		double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); // 두 원의 중심 사이의 거리

		// 예외 케이스
		if (r1 == r2 && x1 == x2 && y1 == y2) { // 두 원이 일치할 때 경우의 수는 무한대
			printf("-1\n"); continue;
		}
		else if (d < (r1 + r2) && d>(r2-r1)) { // 두 점에서 만난다
			printf("2\n"); continue;
		}
		else if(d == (r1 + r2) || d == (r2-r1)) { // 한 점에서 만난다
			printf("1\n"); continue;
		}
		else { 
			printf("0\n"); continue;
		}
	}

	return 0;
}
