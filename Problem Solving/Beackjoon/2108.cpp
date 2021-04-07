#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N = 0;
	double mean;
	int median, mode, range;
	int* arr;
	cin >> N;
	arr = new int[N];

	mean = 0;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		mean += arr[i];
	}

	// 산술평균
	mean /= (double)N;
	mean = floor(mean + 0.5);

	//정렬
	sort(arr, arr + N);

	// 중앙값
	median = arr[N / 2];

	// 범위
	range = arr[N - 1] - arr[0];

	// 최빈값
	// counting sort처럼, idx [0] = -4000, idx [4000] = 0, idx [8000] = 4000
	// idx = num + 4000
	int count_arr[8001] = { 0, };	
	for (int i = 0;i < N;i++) {
		count_arr[arr[i]+4000]++;
	}

	// max_count 구하기
	int max_count = 0;
	for (int i = 0;i < 8001;i++) {
		if (max_count < count_arr[i])
			max_count = count_arr[i];
	}

	int c = 0;
	bool is_first = true;
	for (int i = 0;i < 8001;i++) {
		if (max_count == count_arr[i]) {
			mode = i - 4000;
			if (is_first)	is_first = false;
			else break;
		}
	}

	printf("%0.lf\n%d\n%d\n%d\n", mean, median, mode, range);
}
