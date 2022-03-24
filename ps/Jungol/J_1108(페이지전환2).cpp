/*
2021-04-19
J 1108 페이지 전환
all pairs shortest path problem with 다익스트라
*/
#include <iostream>
using namespace std;

#define VERTEX 500
#define INF 987654321
#define MIN(a, b) ((a)<(b))?(a):(b)

int A[VERTEX][VERTEX] = { 0, };
int D[VERTEX] = { 0, };
int U[VERTEX] = { 0, }; // visit

int V = 0;

int MAX(int a, int b, int c) {
	if (a > b) {
		if (a > c) return a;
	}
	else { // a < b
		if (c > b) return c;
		else return b;
	}
}

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


int dijkstra(int s) {
	for (int v = 1; v <= V; v++) {
		if (A[s][v] != INF) {
			D[v] = A[s][v];
		}
	}
	D[s] = 0;
	U[s] = true;
	for (int i = 1; i <= V; i++) {
		int w = exetract_min();
		U[w] = true;

		for (int v = 1; v <= V; v++) {
			if (A[w][v] != INF && D[v] > D[w] + A[w][v]) {
				D[v] = D[w] + A[w][v];
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= V; i++)  ret += D[i];
	return ret;
}

int main() {

	int N = 0; cin >> N;

	// 무한대로 초기화
	for (int i = 0; i < VERTEX; i++) {
		for (int j = 0; j < VERTEX; j++) {
			if (i == j) continue;
			A[i][j] = INF;
		}
		D[i] = INF;
	}

	for (int n = 0; n < N; n++) {
		int i = 0, j = 0;
		cin >> i >> j;

		A[i][j] = 1;
		V = MAX(V, i, j);
	}

	int min_dist = 0;
	// 다익스트라 출발점 1~V
	for (int k = 1; k <= V; k++) {
		min_dist += dijkstra(k);

		// D, U 초기화
		for (int i = 0; i < VERTEX; i++) {
			D[i] = INF;
			U[i] = false;
		}
	}

	printf("%.3lf\n", min_dist / (double)(V * (V - 1)));

	return 0;
}
