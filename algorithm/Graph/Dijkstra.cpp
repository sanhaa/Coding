#include <iostream>
using namespace std;

const int VERTEX = 10;
const int INF = 987654321;

int A[VERTEX][VERTEX] = { 0, }; // 인접행렬
int D[VERTEX] = { 0, }; // 거리갱신 (s ~ 해당 정점 까지 거리)
bool U[VERTEX] = { 0, }; // visit 여부 표시 false로 최고하
int V = 0; // 정점 총 개수

int exetract_min() {
	int min_v = 0;
	int min_dist = INF;
	// 모든 정점에 대해서
	for (int i = 1; i <= V; i++) {
		// 아직 방문하지 않은 정점 중에 거리가 가장 작은 것 찾기
		if (U[i] == false && min_dist > D[i]) {
			min_dist = D[i]; min_v = i; // min vertex 갱신
		}
	}
	return min_v;
}

void print_dist() {
	for (int i = 0; i < V; i++) {
		printf("%3c", 'A' + i);
	}
	printf("\n");
	
	for (int i = 1; i <= V; i++) {
		printf("%3d", D[i]);
	}
	printf("\n");

	
}

int dijkstra(int s) {
	U[s] = true; // 시작정점 방문

	D[s] = 0;
	for (int v = 1; v <= V; v++) { // 시작 정점과 인접한 정점 가중치 저장
		D[v] = A[s][v];
	}

	for (int i = 1; i < V; i++) {
		/* 우선순위 큐로 구현할 수 있다. */
		int w = exetract_min();
		U[w] = true;

		for (int v = 1; v <= V; v++) {
			// 인접해 있는 정점, 그리고 경유해서 가는 거리가 더 짧으면
			if (A[w][v] != INF && D[v] > D[w] + A[w][v]) {
				D[v] =  D[w] + A[w][v]; // s-v까지의 거리 업데이트
			}
		}
	}

	return D[V];
}

int main() {

	freopen("dijkstra_input.txt", "r", stdin);

	cin >> V;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cin >> A[i][j];
			if (i != j && A[i][j] == 0) A[i][j] = INF;
		}
	}

	int distance = dijkstra(1);
	cout << "min distance : " << distance << endl;

	print_dist();

	return 0;
}
