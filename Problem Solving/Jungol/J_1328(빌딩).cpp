/*
2021-04-28
J 1328 빌딩
자료구조(스택)
*/
#include <iostream>
#include <stack>

using namespace std;

#define MAX_N 100010

struct Building {
	int idx = 0;
	int h = 0;
	Building() {};
	Building(int _idx, int _h) {
		idx = _idx; h = _h;
	}
};

int main() {
	int N = 0; cin >> N;
	stack<Building> st;
	int ans[MAX_N] = { 0, };

	for (int i = 1; i <= N; i++) {
		int hi = 0;
		cin >> hi;
		Building b = Building(i, hi);

		while (!st.empty() && st.top().h < hi) {
			ans[st.top().idx] = i;
			st.pop();
		}
		st.push(b);
	}

	while (!st.empty()) {
		ans[st.top().idx] = 0;
		st.pop();
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
