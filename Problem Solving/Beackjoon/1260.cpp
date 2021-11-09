#include <iostream>
#include <queue>

using namespace std;

int SIZE = 0;
int* visited;
int** a;

// 재귀를 이용한 DFS
void DFS(int v) {
	visited[v] = 1;
	cout << v << " ";
	for (int i = 0;i < SIZE;i++) {
		if (a[v][i] == 1 && visited[i]==0)	// 간선이 연결되어 있고, 방문하지 않은 정점일 때만. 
			DFS(i);
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	SIZE = N + 1;

	// 인접행렬 a선언 및 0으로 초기화
	a = new int* [SIZE];
	for (int i = 0;i < SIZE;i++) {
		a[i] = new int[SIZE]();
	}
	
	// M개의 간선 정보를 입력받고, 인접행렬에 1로 표시
	for (int i = 0;i < M;i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	visited = new int[SIZE]();	// N짜리 배열 동적할당 및 0으로 초기화

	// DFS
	DFS(V);
	cout << "\n";

	delete[] visited;	

	// BFS
	visited = new int[SIZE]();

	queue<int> q;
	q.push(V);
	visited[V] = 1;
	while (!q.empty()) {
		for (int i = 0;i < SIZE;i++) {
			if (a[q.front()][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
			}
		}
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";

	for (int i = 0;i < SIZE;i++) {
		delete[] a[i];
	}
	delete[] a;
	delete[] visited;

}
