// BFS로 최단거리 구하기
#include <iostream>
using namespace std;

const int VERTEX = 10;
const int INF = 987654321; // 일반적인 정수 최대값

int A[VERTEX][VERTEX] = { 0, }; // 인접행렬
int D[VERTEX] = { 0, }; // 거리갱신 (s ~ 해당 정점 까지 거리)
int V = 0; // 정점 총 개수

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

int shortest_bfs(int s) {
	// queue
	int q[100] = { 0, };
	int front = -1, rear = -1;

	D[s] = 0;
	q[++rear] = s; // enqueue

	while(front != rear) {
		int w = q[++front]; // dequeue

		//if (w == V) return D[V]; // 끝까지 갔다

		for (int v = 1; v <= V; v++) {
			// 인접해 있는 정점, 그리고 경유해서 가는 거리가 더 짧으면
			if (A[w][v] != INF && D[v] > D[w] + A[w][v]) {
				D[v] = D[w] + A[w][v]; // s-v까지의 거리 업데이트
				q[++rear] = v; // enqueue
			}
		}
	}

	return D[V]; // 답을 구하지 못한 경우
}

int main() {

	freopen("dijkstra_input.txt", "r", stdin);

	cin >> V;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cin >> A[i][j];
			if (i != j && A[i][j] == 0) A[i][j] = INF;
		}
		D[i] = INF; // 초기화
	}

	int distance = shortest_bfs(1);
	cout << "min distance : " << distance << endl;

	print_dist();

	return 0;
}
