// S 1267 작업순서
// 위상정렬 사용, 진입 차수 감소 순서를 
#include <iostream>
using namespace std;

const char sharp = '#';
const int MAX_V = 1001;
int A[MAX_V][MAX_V] = { 0, }; // 인접 행렬

void print_A(int A[MAX_V][MAX_V], int V){
	for (int i = 0; i <= V; i++) { // indegree 같이 출력
		for (int j = 1; j <= V; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}

void topological_sort(int A[MAX_V][MAX_V], int V) {
	int q[MAX_V] = { 0, };
	int front = -1, rear = -1;

	for (int i = 1; i <= V; i++) {
		if (A[0][i] == 0) { // 진입차수가 0인거
			q[++rear] = i;  // enqueue
		}
	}

	while(front != rear){
		int i = q[++front]; // dequeue
		A[0][i]--; // 진입차수 -1
		cout << i << " ";

		for (int j = 1; j <= V; j++) {
			if (A[i][j] == 1 && --A[0][j] == 0) { // i->j 길이 있다
				q[++rear] = j; // enqueue
			}
		}
	}
}

int main() {

	int T = 10;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < MAX_V; i++) {
			fill_n(A[i], MAX_V, 0); // 초기화
		}

		int V = 0, E = 0; // 1 ~ V 정점까지 
		cin >> V >> E;

		for (int i = 1; i <= E; i++) {
			int from, to;
			cin >> from >> to;
			A[from][to] = 1;
			A[0][to]++; // 진입 차수 카운팅
		}

		cout << sharp << t << " ";
		topological_sort(A, V);
		cout << "\n";
	}

	return 0;
}
