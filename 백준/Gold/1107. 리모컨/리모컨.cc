// BOJ 1107 리모컨
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> buttons ;
int N = 0, M = 0;
int len = 0;
string sN = "";
int ans = 0;

int abs(int a) {
	return a > 0 ? a : -a;
}

void solve(string num) {
	int l = num.length();
	if (l >= 7) return;
	//if (l == len) {
		int diff = N - stoi(num);
		int cur = diff > 0 ? diff : -diff;
		cur += l;
		if (ans > cur) ans = cur;

		//return;
	//}
	for (int n : buttons) {
		solve(num + char(n + '0'));
	}
	
}

int main() {
	cin >> N >> M;
	sN = to_string(N);
	len = sN.length();

	bool broken[10] = { 0, };
	for (int i = 0; i < M; i++) {
		int a = 0; cin >> a;
		broken[a] = true;
	}

	ans = abs(N - 100); // + - 버튼만 썼을 때
	
	if (M == 0) {
		if(ans > len) ans = len;

	}
	else {
		for (int i = 0; i < 10; i++) {
			if (!broken[i]) buttons.push_back(i);
		}
		for (int n : buttons) {
			string s = "";
			solve(s + char(n + '0'));
		}
	}

	cout << ans << "\n";

	return 0;
}