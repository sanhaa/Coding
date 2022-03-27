// BOJ 7568 덩치
// Brute Force
#include <iostream>

using namespace std;

int main() {
	int N = 0; cin >> N;
	pair<int, int> arr[55];
	for (int i = 0; i < N; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		arr[i] = make_pair(x, y);
	}
	for (int i = 0; i < N; i++) {
		int rank = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) rank++;
		}
		cout << rank + 1 << " ";
	}

	return 0;
}