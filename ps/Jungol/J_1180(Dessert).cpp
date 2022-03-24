/*
2021-04-26
J 1180 : Dessert
알고리즘: 백트래킹
*/
#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 16
#define MAX_SIZE 50

enum OPER{ // 0, 1, 2 우선순위
	ADD, SUB, DOT
};

char operations[3] = { '+', '-', '.' };
int ans_cnt = 0;
int N = 0;
int N0 = 0;

// 식 출력
void print_ans(int forms[]) {
	
	for (int i = 0; i <= N0*2; i+=2) {
		cout << forms[i] << " "; // 숫자 출력
		if (i == N0 * 2) { // 마지막
			cout << " ";
			break;
		}
		cout << operations[forms[i + 1]] <<" ";
	}
	cout << "\n";
}

int calculate(int forms[]) {
	int temp[MAX_SIZE] = { 0, };
	for (int i = 0; i <= 2*N; i++) {
		temp[i] = forms[i];
	}

	// dot 연산처리
	int contd = 0;
	for (int i = 1; i < 2 * N; i+=2) {
		if (temp[i] == DOT) {
			contd++;
			temp[i + 1] = temp[i - 1] * pow(10, (temp[i + 1] / 10 + 1)) + temp[i + 1];
		}
		else {
			//if (contd >= 1) {
				int ii = i - 2;
				while (contd) {
					temp[ii - 1] = temp[ii + 1];
					ii -= 2; contd--;
				}
			//}
			contd = 0;
		}
	}
	
	int res = 0;
	for (int i = 1; i < 2 * N; i+=2) {
		int next = temp[i + 1];
		int prev = temp[i - 1];

		switch (temp[i]) {
		case ADD:
			temp[i + 1] = (prev+ next);  break;
		case SUB:
			temp[i + 1] = (prev - next); break;
		case DOT:
			temp[i + 1] = prev; break;
		default:
			continue;
		}
	}
	return temp[2*N0];
}

// 재귀로 식만 만들기
void backtrack(int n, enum OPER op, int forms[]) {
	// 식 채우기
	forms[n * 2 - 2] = n;
	forms[n * 2 - 3] = op;

	if (n == N) {
		int ret = calculate(forms);

		if (ret != 0) return;
		ans_cnt++;
		if(ans_cnt <=20) print_ans(forms);
		return;
	}

	
	for (int i = 0; i < 3; i++)
		backtrack(n + 1, (enum OPER)i, forms);
}


int main() {
	cin >> N;
	// 냅킨(연산자)는 N-1개
	N0 = N - 1;

	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	int forms[MAX_SIZE] = { 0, };

	forms[0] = 1;
	for (int i = 0; i < 3; i++) {
		forms[1] = i;
		backtrack(2, (enum OPER)i, forms);
	}
	
	cout << ans_cnt << "\n";

	return 0;
}
