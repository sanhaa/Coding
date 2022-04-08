// BOJ 15686 치킨배달
// 재귀 백트래킹
#include <iostream>
#include <vector>

using namespace std;

int N = 0, M = 0;
pair<int, int> home[200]; 
pair<int, int> chicken[20]; 
vector<pair<int, int>> selected;

int home_cnt = 0, chicken_cnt = 0;
int ans = 987654321;

int mabs(int a) {
	return a > 0 ? a : -a;
}

void recurse(int s, vector<pair<int, int>> selected) {

	if (selected.size() == M) {
		// 도시의 치킨거리 구하기
		int city_dist = 0;
		for (int i = 0; i < home_cnt; i++) {
			int dist = 200;
			for (int j = 0; j < M; j++) {
				int d = mabs(home[i].first - selected[j].first) + mabs(home[i].second - selected[j].second);
				if (dist > d) dist = d;
			}
			city_dist += dist;
		}
		if (ans > city_dist) ans = city_dist;
	}

	else {
		// 다음 치킨집
		for (int i = s+1; i < chicken_cnt; i++) {
			selected.push_back(chicken[i]);
			recurse(i, selected);
			selected.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a = 0; cin >> a;
			if (a == 1) {
				home[home_cnt++] = make_pair(i, j);
			}
			else if (a == 2) {
				chicken[chicken_cnt++] = make_pair(i, j);
			}
		}
	}
	vector<pair<int, int>> s;
	recurse(-1, s);
	cout << ans << endl;

	return 0;
}