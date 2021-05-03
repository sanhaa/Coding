/*
기출문제 : 코끼리 서커스
자료형 long long 써야 할까
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 310

int arr[MAX_N] = { 0, };
int p[] = { 0, };
int N = 0; 
int ans_cnt = 0, total_cnt = 0;

void printArray(int* arr) {

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	cout << endl;
}

bool is_answer(int *a) { 

	// 가운데 수들 검사
	for (int i = 1; i < N - 1; i++) {
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) // 커 작 커
			continue;
		else if (a[i] > a[i - 1] && a[i] > a[i + 1]) // 작 커 작
			continue;
		else
			return false;
	}
	return true;
}

// 재귀로 순열 구하기
void Perm(int k) {
	if (k == N) {
		// npr에서 r == n
		total_cnt++;
		if (is_answer(arr)) {
			//printArray(arr);
			ans_cnt++;
		}
	}
	else {
		for (int i = k; i < N; i++) {
			swap(arr[i], arr[k]);
			Perm(k + 1);
			swap(arr[i], arr[k]); // 원래대로 되돌림 = 순서 때문에
		}
	}
}

int main() {

	int tc = 0; cin >> tc;
	for (int i = 0; i < MAX_N; i++) { // 순열 구하기 위해 배열 채워주기
		arr[i] = i + 1;
	}

	for (int t = 0; t < tc; t++) {
		// 테케 반복시 변수 초기화
		ans_cnt = 0; total_cnt = 0;
		cin >> N;

		Perm(0);
		cout << ans_cnt << " of " << total_cnt << endl;
		//cout << "#" << t << " " << ans_cnt << endl;
	}

	return 0;
}
