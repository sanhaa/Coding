// Quick sort = Pivot sort
// 분할정복

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
}

bool compare(int a, int b) {
    return a < b; // 오름차순
	//return a > b; // 내림차순
}

// 오름차순 퀵소트
// 내림차순: compare 함수만 수정하면 된다.
void qsort(vector<int>& numbers, int left, int right) {
	// 길이가 0 또는 1일 때 return
	if (right - left <= 0) return;

	int pivot = numbers[left];
	int low = left, high = right;

	while (true) {
		while (low < right){
			// 오름차순: find [low] > pivot
			if (compare(pivot, numbers[low])) break;
			low++;
		}
		while (high > left) {
			// 오름차순: find [high] < pivot
			if (compare(numbers[high], pivot)) break;
			high--;
		}
		// low와 high가 교차되면 종료
		if (low >= high) break;

		swap(numbers[low], numbers[high]);
	}


	// pivot index 찾기
	int pivot_idx = high;
	swap(numbers[left], numbers[pivot_idx]);

	// Divie: pivot 위치 기준으로 새로운 left, right 넘겨주어 numbers 분할하는 효과
	qsort(numbers, left, pivot_idx - 1);
	qsort(numbers, pivot_idx + 1, right);
}

int main() {
	vector<int> numbers = { 5, 2, 6, 9, 7, 1, 3, 4, 8 };

	qsort(numbers, 0, numbers.size()-1);

	for (int n : numbers) {
		cout << n << " ";
	} cout << endl;

	return 0;
}
