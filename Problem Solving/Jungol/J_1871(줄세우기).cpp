/*
2021-04-20
J 1871 줄세우기
*/
#include <iostream>
using namespace std;

#define MAX_N 210
#define MAX(a, b) ((a)>(b))?(a):(b)

int main(){
	int N = 0; cin >> N;
	int LIS[MAX_N] = { 0, };
	int arr[MAX_N] = { 0, };

	for (int n = 1; n <= N; n++)
		cin >> arr[n];

	for (int i = 1; i <= N; i++) {
		if(LIS[i] == 0) LIS[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				// 최대 증가 수열 길이는 현재 수를 포함 or 포함 안함
				//LIS[i] = MAX(LIS[j] + 1, LIS[i]);
				if (LIS[i] < LIS[j] + 1) LIS[i] = LIS[j] + 1;
			}
		}
	}


	cout << (N - LIS[N]) << endl;
}
