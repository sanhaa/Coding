// BOJ 1197 최소 스패닝 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_N = 10001;

int A[MAX_N][MAX_N] = { 0, }; // 간선 정보 저장 -> 인접 배열은 메모리 초과, 인접 리스트 사용해야 한다.

struct Vertex {
	int idx = 0;
	int cost = INF; // key
	int parent = 0; // pi, parent idx
	Vertex() {};
	Vertex(int _idx, int _cost, int _parent) {
		idx = _idx; cost = _cost; parent = _parent;
	}
};

struct cmp {
	bool operator()(Vertex a, Vertex b) {
		return a.cost > b.cost;
	}
};

int main() {

	int N = 0, M = 0;
	cin >> N >> M;
	bool visit[MAX_N] = { 0 };
	int cost[MAX_N];

	// init
	for (int i = 0; i <= N; i++) {
		cost[i] = INF;
		visit[i] = false;
		for (int j = 0; j <= N; j++) {
			if (i == j) continue;
			A[i][j] = INF;
		}
	}

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		A[a][b] = c;
		A[b][a] = c;
	}

	int min_cost = 0;
	priority_queue<Vertex, vector<Vertex>, cmp> pq;
	pq.push(Vertex(1, 0, 0)); // 시작 정점

	while (!pq.empty()) {
		Vertex now = pq.top();
		pq.pop();
		if (visit[now.idx] == true)
			continue;

		min_cost += now.cost;
		visit[now.idx] = true;

		for (int i = 1; i <= N; i++) {
			if (A[now.idx][i] < cost[i]) {
				cost[i] = A[now.idx][i];
				pq.push(Vertex(i, cost[i], now.idx));
			}
		}
	}

	cout << min_cost << endl;

	return 0;
}
