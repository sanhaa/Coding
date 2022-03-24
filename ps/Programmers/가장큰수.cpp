// 프로그래머스 - 코딩테스트 연습 가장큰수
// 정렬
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
}

// 문자열 비교
bool compare(int a, int b) {
	string sa = to_string(a), sb = to_string(b);
	return (sa + sb) > (sb + sa);
}

// call by reference
void msort(vector<int>& numbers, int left, int right) {
	if (right - left <= 0) {
		return;
	}

	int pivot = numbers[left];
	int low = right, high = left + 1;

	while (true) {
		while (low > left) {
			// find [low] > pivot
			if (compare(numbers[low], pivot)) break;
			low--;
		}
		while (high <= right) {
			// find [high] < pivot
			if (compare(pivot, numbers[high])) break;
			high++;
		}
		if (low < high) break;

		swap(numbers[low], numbers[high]);
	}

	// pivot index 찾기
	int pivot_idx = low;
	swap(numbers[left], numbers[pivot_idx]);

	// Divie: pivot 위치 기준으로 새로운 left, right 넘겨주어 numbers 분할하는 효과
	msort(numbers, left, pivot_idx - 1);
	msort(numbers, pivot_idx + 1, right);
}


string solution(vector<int> numbers) {
	string answer = "";
	//sort(numbers.begin(), numbers.end(), compare);
	msort(numbers, 0, numbers.size() - 1);

	for (int a : numbers) answer += to_string(a);

	return answer[0]=='0' ? "0":answer;
} 

int main() {
	vector<int> numbers = { 3, 30, 34, 5, 9 };

	cout<<solution(numbers)<<endl;
	//cout << compare(343, 3) << endl; // 3334 3343

	return 0;
}
