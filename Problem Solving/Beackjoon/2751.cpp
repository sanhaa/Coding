// #2751

#include <iostream>
#include <algorithm>
using namespace std;

//sort 함수 사용
int main() {
	int N, * arr;
	cin >> N;
	arr = new int[N];

	for (int i = 0;i < N;i++) cin >> arr[i];

	sort(arr, arr + N);
	for (int i = 0;i < N;i++) cout << arr[i] << "\n";
}
