// Binary search 구현(반복문)
// 재귀를 이용한 구현은 느려서 잘 사용하지 않는다.
// 오버플로우 생각하기,
// int 뿐만 아니라 long long int도 생각하기
#include <iostream>
#include <algorithm>


using namespace std;

int binarySearch(int *arr, int n, int key) {

	int low = 0;
	int high = n - 1;

	while (low <= high) {
		//int mid = (low + high) / 2; // 문제 있는 이유: low + hitg가 오버플로우 가능성
		// int low, int high -> low+high => longlong int 가 될 수 있음
		int mid = low + high / 2;

		if (mid > n) break;
		if (arr[mid] < key) {
			low = mid + 1;
		}
		else if(arr[mid] > key) {
			high = mid - 1 ;
		}
		else { // 찾았다.
			return mid;
		}
	}
	return -1;

}

int main() {

	int arr[] = { 1, 3, 4, 8, 2, 5, 6, 9, 7, 10};
	int n = sizeof(arr) / sizeof(arr[0]); // 배열 길이 구하기

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int idx = binarySearch(arr, n, 11);

	cout << idx << endl;
}
