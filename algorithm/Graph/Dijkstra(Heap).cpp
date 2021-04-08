// 다익스트라 heap으로 구현
// heap 대신 pq 써도 된다.
#include <iostream>
using namespace std;

const int VERTEX = 20;
const int INF = 987654321;

int A[VERTEX][VERTEX] = { 0, }; // 인접행렬
int D[VERTEX] = { 0, }; // 거리갱신 (s ~ 해당 정점 까지 거리)
bool U[VERTEX] = { 0, }; // visit 여부 표시 false로 최고하
int V = 0; // 정점 총 개수

// Heap
const int HEAP_SIZE = 10;
int heap[HEAP_SIZE] = { 0, };
int heapCount = 0; // 1부터 시작, 현재 노드 개수

void push(int value) {
	heap[++heapCount] = value; // 무조건 마지막 leaf노드에 추가
	int child = heapCount; // 추가된 노드의 인덱스
	int parent = child / 2; // 부모 = 자식/2

	while (parent > 0 && D[heap[parent]] > D[heap[child]]) {
		// 더 작은 값을 위로 올려야 한다.
		// parent, child swap
		//int tmp = heap[parent];
		//heap[parent] = heap[child];
		//heap[child] - tmp;
		swap(heap[parent], heap[child]);

		child = parent;
		parent = child / 2;
	}
	cout << "pushed : " << value << endl;
}

// PQ로 운영하는 경우 extractMin(), extractMax() 이름 사용
int pop() { // -> extractMin()
	int parent = 1; // root 노드 삭제
	int ret = heap[parent];
	// 마지막 leaf -> root채우기
	heap[parent] = heap[heapCount];
	heap[heapCount] = 0; --heapCount; // 개수 하나 줄이기

	int child = parent * 2; // left
	if (child + 1 <= heapCount) {
		// 오른쪽 자식이 존재하면 크기 비교해서 어느 자식이 swap 될건지 찾기(더 작은 자식이 위로 올라감)
		child = D[heap[child]] < D[heap[child + 1]] ? child : child + 1;
	}

	while (child <= heapCount && D[heap[parent]] > D[heap[child]]) {
		// parent, child swap
		//int tmp = heap[parent];
		//heap[parent] = heap[child];
		//heap[child] - tmp;
		swap(heap[parent], heap[child]);

		child = parent;
		parent = child / 2;
		if (child + 1 <= heapCount) {
			child = D[heap[child]] < D[heap[child + 1]] ? child : child + 1;
		}
	}

	return ret;
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

// O(VlogE)
// priority queue를 이용한(사실은 heap) 다익스트라 알고리즘
int dijkstra(int s) {
	//U[s] = true; // 시작정점 방문

	//for (int v = 1; v <= V; v++) { // 시작 정점과 인접한 정점 가중치 저장
	//	D[v] = A[s][v];
	//}

	D[s] = 0;
	push(s);

	// 힙이 비어있지 않은 동안 !empty()
	while (heapCount > 0) {
		int w = pop();

		U[w] = true;

		for (int v = 1; v <= V; v++) {
			// 인접해 있는 정점, 그리고 경유해서 가는 거리가 더 짧으면
			if (A[w][v] != INF && D[v] > D[w] + A[w][v]) {
				D[v] = D[w] + A[w][v]; // s-v까지의 거리 업데이트
				push(v);
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
		D[i] = INF;
		U[i] = false;
	}

	int distance = dijkstra(1);
	cout << "min distance : " << distance << endl;

	print_dist();

	return 0;
}
