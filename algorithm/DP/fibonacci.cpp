// simpe DP with fibonacci
#include <iostream>
using namespace std;

long long fibo_repeat(int n) {
	long long table[1000] = { 0,1 };

	for (int i = 2; i <= n; i++) {
		table[i] = table[i - 1] + table[i - 2];
	}

	return table[n];
}

// 슬라이딩 윈도우 기법을 사용하여 메모리 절약
// 반복적인 DP에 사용
long long fibo_slide(int n) {
	const int WIN_SIZE = 3;
	long long table[WIN_SIZE] = { 0,1, };

	for (int i = 2; i <= n; i++) {
		table[i%WIN_SIZE] = table[(i - 1) % WIN_SIZE] + table[(i - 2) % WIN_SIZE];
	}
	
	return table[n%WIN_SIZE];
}

int main() {

	int n = 50;

	cout<< fibo_repeat(n)<<endl;
	cout<< fibo_slide(n)<<endl;

}
