#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//sort 함수 사용
int main() {
	int N = 0;
	cin >> N;
	vector<int> v;

	while (N-- > 0) {
		int x = 0;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << "\n";
	}
}