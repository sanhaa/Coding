// BOJ 1976 여행 가자
// 유니온 파인드, 분리 집합
// 여행 계획으로 주어지는 도시가 모두 같은 부모를 가지는지 확인

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 210;

vector<int> p(MAXN),r(MAXN); 

void union_set(int a, int b) {
	if (r[a] > r[b]) {
		p[b] = a;
	}
	else {
		p[a] = b;
		if (r[a] == r[b]) r[b]++;
	}
}

int find_parent(int a) {
	if (p[a] == a) return a;
	else {
		p[a] = find_parent(p[a]);
		return p[a];
	}
}

int main() {

	int N = 0, M = 0;	cin >> N >> M;

	// init vector
	for (int i = 0; i <= N; i++) {
		p[i] = i;
		r[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int is_conn = 0; cin >> is_conn;
			if (is_conn) {
				int pa = find_parent(i), pb = find_parent(j);
				if (pa != pb) // 이전에 연결된 두 도시가 아니라면
					union_set(pa, pb);
			}
		}
	}

	// 여행 계획
	bool is_possible = true;
	int parent = 0;
	for (int i = 0; i < M; i++) {
		int city = 0; cin >> city;
		if (parent == 0) parent = find_parent(city);
		else {
			if (parent != find_parent(city)) {
				is_possible = false;
			}
			parent = find_parent(city);
		}
	}
	cout << (is_possible ? "YES" : "NO") << "\n";

	return 0;
}