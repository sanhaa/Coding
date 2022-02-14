
/*
2021-04-15
Sanhaa
J 1545 해밀턴 순환회로 2
 - DP를 이용한 풀이
*/
#include <iostream>
using namespace std;

#define MAX_N 20
#define INF 987654321
#define MIN(a, b) ((a)<(b))?(a):(b)

int N = 0;

// 2의 거듭제곱인지 확인
bool is_pow2(int n) {
	return (n == (n&-n));
}

// 2의 거듭제곱인 n을 이진수로 표현했을 때 1이 나오는 위치
int digit(int n) {
	int ret = 0;
	while (n) {
		ret++;
		n = n >> 1;
	}
	return ret - 1;
}

// j : A 경로 표시 집합
int D[MAX_N][1 << MAX_N] = { 0, }; // [i]: 출발 정점 [j]: 집합 A에 속한 원소 표시(표시된 원소를 방문해야 함)
int W[MAX_N][MAX_N] = { 0, };

int tsp(int src, int A) {

	if (D[src][A] != 0) return D[src][A]; // 이미 있는 값이면 이용

	// 재귀 종료 조건
	if (is_pow2(A)) { // 방문할 정점이 한개 남았을 때
		int digitA = digit(A);
		return D[src][A] = (W[src][digitA] + W[digitA][0]);
	}

	int ans = INF;
	// DP[src][A]
	for (int dst = 1; dst < N; dst++) {
		//비트가 꺼져있으면 방문할 필요 없다
		if (dst == src || ((A & (1 << (dst))) == 0) || W[src][dst] == INF) continue;
		int cost = D[dst][A & ~(1 << dst)];

		if (cost != 0)  ans = MIN(ans, W[src][dst] + cost);
		else ans = MIN(ans, W[src][dst] + tsp(dst, A & ~(1 << dst)));
	}
	D[src][A] = ans;

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; // <=19
	// input
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j]; // 가중치 입력받기
			if (i != j && W[i][j] == 0) W[i][j] = INF; // i-j not connected
		}
	}

	int A = (1 << N) - 1; // N개 bit를 모두 on

	cout << tsp(0, A & ~(1)) << "\n"; // 1은 방문한걸로 처리

	return 0;
}
