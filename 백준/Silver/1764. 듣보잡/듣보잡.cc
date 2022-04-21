// BOJ 1764 듣보잡
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N = 0, M = 0;
	cin >> N >> M;

	map<string, int> m;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		m.insert(make_pair(s, i));
	}

	vector<string> ans;
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		map<string, int>::iterator iter = m.find(s);
		if (iter != m.end()) {
			// find
			ans.push_back((*iter).first);
			cnt++;
		}
	}

	cout << cnt << "\n";
	sort(ans.begin(), ans.end());
	for (string s : ans)
		cout << s << "\n";

	return 0;
}