// BFS와 DFS
// 알맞은 자료구조 (stack, que) 준비, visit 배열 준비
// 1. 자료구조에 시작 정점을 넣는다.
// 2. 자료구조가 비어있지 않을동안
// 3. 자료구조에서 하나 꺼내서 visit 체크하고
// 4. 인접한 노드 자료구조에 다시 넣는다.
// 5. 3.으로가서 반복한다.

#include <iostream>
using namespace std;

const int GRAPH_SIZE = 10;
const int STACK_SIZE = 20;
const int QUEUE_SIZE = 20;

int V, E; // 정점, 간선 개수
int G[GRAPH_SIZE][GRAPH_SIZE] = { 0, };
bool visit[GRAPH_SIZE] = { 0, };

// Stack
int st[STACK_SIZE] = { 0, };
int top = -1;

// QUEUE
int q[QUEUE_SIZE] = { 0, };
int front = -1;
int rear = -1;

// Stack 구현
bool isEmpty() {
	if (top <= 0) return true;
	else return false;
}

void push(int val) {
	st[++top] = val;
}

int pop() {
	return st[top--];
}

// Queue 구현
bool QisEmpty() {
	if (front == rear) return true;
	else return false;
}

void enQueue(int val) {
	q[++rear] = val;
}

int deQueue() { 
	return q[++front];
}

// v: 시작 정점
void DFS_loop(int v) {
	//st[++top] = v;
	push(v);
	
	while (top >= 0) {
		//v = st[top--]; // pop
		v = pop();

		if (visit[v] == false) {
			visit[v] = true;
			cout << v << " ";

			for (int w = V; w > 0; w--) {
				if (G[v][w] == 1 && visit[w] == false) {
					//st[++top] = w;
					push(w);
				}
			}
		}
	}
}

void DFS_recur(int v) {
	visit[v] = true;
	cout << v << " ";

	for (int w = 1; w <= V; w++) {
		if (G[v][w] == 1 && visit[w] == false) {
			DFS_recur(w);
		}
	}

}

void BFS(int v) {
	enQueue(v);
	//q[++rear] = v;

	while (!QisEmpty() /*front != rear*/) {
		v = deQueue();
		//v = q[++front]; // dequeue

		if (visit[v] == false) {
			cout << v << " ";
			visit[v] = true;

			for (int w = 1; w <= V; w++) {
				if (G[v][w] == 1 && visit[w] == 0) {
					enQueue(w);
					//q[++rear] = w;
				}
			}
		}
	}
}

int main() {

	freopen("graph_input.txt", "r", stdin);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int begin, end;
		cin >> begin >> end;

		// 방향 없음
		G[begin][end] = G[end][begin] = 1;
	}

	cout << "DFS(반복)\n";
	DFS_loop(1); // 1 2 4 6 5 7 3

	// visit 배열 초기화
	fill_n(visit, GRAPH_SIZE, false);
	cout << endl;

	cout << "\nDFS(재귀)\n";
	DFS_recur(1);  // 1 2 4 6 5 7 3

	fill_n(visit, GRAPH_SIZE, false);
	cout << endl;

	cout << "\nBFS\n";
	BFS(1); // 1 2 3 4 5 7 6

	cout << endl;
	return 0;
}
