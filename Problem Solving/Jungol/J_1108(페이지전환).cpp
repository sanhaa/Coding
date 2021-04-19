/*
2021-04-19
J 1108 페이지 전환
모든 쌍 최단 거리 문제 : 플로이드, 다익스트라
*/
#include <iostream>
using namespace std;

#define VERTEX 500
#define INF 987654321
//#define MAX(a, b) ((a)>(b))?(a):(b)
#define MIN(a, b) ((a)<(b))?(a):(b)

int d[VERTEX][VERTEX] = { 0, };

int MAX(int a, int b, int c) {
	if (a > b) {
		if (a > c) return a;
	}
	else { // a < b
		if (c > b) return c;
		else return b;
	}
}

int main() {

	int N = 0; cin >> N;

	int V = 0;

	// 무한대로 초기화
	for (int i = 0; i < VERTEX; i++) {
		for (int j = 0; j < VERTEX; j++) {
			if (i == j) continue;
			d[i][j] = INF;
		}
	}

	for (int n = 0; n < N; n++) {
		int i = 0, j = 0;
		cin >> i >> j;

		d[i][j] = 1;
		V = MAX(V, i, j);
	}

	// 플로이드 와샬
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				// k를 경유해서 가는게 더 빠르면 기존 값 갱신
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int min_dist = 0;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			min_dist += d[i][j];
		}
	}

	printf("%.3lf\n", min_dist / (double)(V * (V - 1)));

	return 0;
}
