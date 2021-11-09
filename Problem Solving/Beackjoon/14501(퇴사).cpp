/*
2021-04-22
백준 14501 퇴사
알고리즘: 부분집합 활용
*/
#include <iostream>
using namespace std;

#define MAX_N 17

int max_profit = 0; // answer
int N = 0;
int T[MAX_N] = { 0, };
int P[MAX_N] = { 0, };

int arr[MAX_N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
int t[] = { 0, };

int MAX(int a, int b) {
	return a > b ? a : b;
}

void print_array(int t[], int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", t[i]);
	}
	printf("}\n");
}

bool is_possible(int t[], int n) {
	int next_day = 0, profit = 0;

	for (int i = 0; i < n; i++) {
		if (next_day > t[i]) {
			return false;
		}
		next_day = t[i] + T[t[i]];
		profit += P[t[i]];
	}

	if (next_day > N + 1) return false;
	if (max_profit < profit) {
		max_profit = profit;
		cout << max_profit << " ";
		print_array(t, n);
	}
	//else max_profit = MAX(max_profit, profit);

	return true;
}

// nCr = (n-1)C(r-1)  + (n-1)Cr
// q는 숫자 개수
void nCr(int n, int r, int q) {
	if (r == 0) {
		// check 
		bool ret = is_possible(t, q);
		//if(ret == 1) print_array(t, q);
	}
	else if (n < r) return;
	else {
		t[r - 1] = arr[n - 1];
		nCr(n - 1, r - 1, q);
		nCr(n - 1, r, q);
	}
}

int main() {
	cin >> N;
	// 1 ~ N일 상담 정보
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];

	// 부분집합 구하기
	for (int i = 1; i <= N; i++) {
		nCr(N, i, i);
	}

	cout << max_profit << endl;

	return 0;
}
