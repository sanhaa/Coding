#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_N = 101;

struct Vertex {
	int idx = 0;
	int dist = INF; // key
	int parent = 0; // pi, parent idx
	Vertex() {};
	Vertex(int _idx, int _dist, int _parent) {
		idx = _idx; dist = _dist; parent = _parent;
	}
};

struct cmp {
	bool operator()(Vertex a, Vertex b) {
		return a.dist > b.dist;
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	int N = 0;
	cin >> N;
	int A[MAX_N][MAX_N] = { 0, }; // 간선 정보 저장
	bool visit[MAX_N] = { 0 };
	int dist[MAX_N];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
		dist[i] = INF;
	}
	int min_dist = 0;
	priority_queue<Vertex, vector<Vertex>, cmp> pq;
	pq.push(Vertex(1, 0, -1));

	while (!pq.empty()) {
		Vertex now = pq.top();
		pq.pop();
		if (visit[now.idx] == true) continue;
		min_dist += now.dist;
		visit[now.idx] = true;

		for (int i = 1; i <= N; i++) {
			if (visit[i] == false && A[now.idx][i] < dist[i]) {
				dist[i] = A[now.idx][i];
				pq.push(Vertex(i, dist[i], now.idx));
			}
		}

	}
	cout << min_dist << endl;
}
