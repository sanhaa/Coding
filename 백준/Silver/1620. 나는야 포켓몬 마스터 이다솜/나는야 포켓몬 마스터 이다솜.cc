// BOJ 1620 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;
	map<int, string> name_of;
	map<string, int> number_of;

	for (int i = 1; i <= N; i++) {
		string name; cin >> name;
		name_of.insert(make_pair(i, name));
		number_of.insert(make_pair(name, i));
	}

	while (M--) {
		string in; cin >> in;
		if (in[0] >= '1' && in[0] <= '9') { // 숫자
			cout << (*name_of.find(stoi(in))).second << "\n";
		}
		else {
			cout << (*number_of.find(in)).second << "\n";
		}
	}

	return 0;
}