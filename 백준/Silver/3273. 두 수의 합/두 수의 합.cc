// BOJ 3273 두 수의 합
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0, x = 0;
	vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a = 0; cin >> a;
		arr.push_back(a);
	}
	cin >> x;

	sort(arr.begin(), arr.end());

	int cnt = 0; // two pointer
	vector<int>::iterator s = arr.begin();
	vector<int>::iterator e = arr.end() - 1;

	while (s < e) {
		int sum = *s + *e;
		if (sum == x) {
			cnt++;
			s++; e--;
		}
		else if (sum < x) s++;
		else if (sum > x) e--;
	}

	cout << cnt << "\n";

	return 0;
}