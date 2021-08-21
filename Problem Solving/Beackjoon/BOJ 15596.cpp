// BOJ 15596 정수 N개의 합
// 함수 구현
// a[i]<= 100만, n<3백만

#include <iostream>
#include <vector>

/* C++ */
//long long sum(std::vector<int>& a) {
//	long long ret = 0;
//	for (int aa:a) {
//		ret += aa;
//	}
//
//	return ret;
//}

/* C */
long long sum(int* a, int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	return ans;
}

int main() {
	int arr[10]  = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout<<"sum: " << sum(arr, 10) << std::endl;

	return 0;
}