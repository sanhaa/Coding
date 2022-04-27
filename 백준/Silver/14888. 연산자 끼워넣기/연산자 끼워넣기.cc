// BOJ 14888 연산자 끼워넣기
#include <iostream>

using namespace std;

const int MAXN = 12;
int A[MAXN] = { 0, }, N = 0, maxv = -987654321, minv = 987654321;
int all_op[MAXN] = { 0, };

enum {
	PLUS=1, MINUS, MULTI, DIV
};

// idx: 현재 operation이 들어갈 위치
// opers: 현재까지 operation 순서
// used: all_op[i] 사용 여부
void put_oper(int idx, int opers[MAXN], bool used[MAXN]) {
	if (idx == N - 1) {
		// 연산하기
		int res = A[0];
		for (int i = 1; i < N; i++) {
			switch (opers[i])
			{
			case PLUS:
				res = res + A[i]; break;
			case MINUS:
				res = res - A[i]; break;
			case MULTI:
				res = res * A[i]; break;
			case DIV: // 음수 나눗셈
				res = res / A[i]; break;
			default:
				break;
			}
		}

		if (res > maxv) maxv = res;
		if (res < minv) minv = res;
		return;
	}

	// 다음 자리 연산자
	for (int i = 0; i < N-1; i++) {
		if (used[i]) continue;
		used[i] = true;
		opers[idx + 1] = all_op[i];
		put_oper(idx + 1, opers, used);
		used[i] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int op = PLUS, cnt = 0;
	for (int i = 0; i < 4; i++) {
		int a = 0; cin >> a;
		for (int j = cnt; j < cnt + a; j++) {
			all_op[j] = op;
		}
		op++; cnt += a;
	}

	int opers[MAXN] = { 0, };
	bool used[MAXN] = { 0, };
	put_oper(0, opers, used);

	cout << maxv << "\n" << minv << "\n";

	return 0;
}
