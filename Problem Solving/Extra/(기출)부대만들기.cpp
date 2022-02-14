/*
기출 : 부대 만들기
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

int N = 0;
int city[MAX_N] = { 0, };
vector<int> A[MAX_N];

void print_A(int N) {
	for (int i = 1; i <= N; i++) {
		for (auto j : A[i]) {
			//if (A[i][j] == 0) break;
			cout << j << " ";
		}
		cout << endl;
	}
}

int max = 0;
bool visit[MAX_N] = { 0, };

// blue 사단, yellow 사단에 들어갈 도시 고르기
// blue 사단의 도시들의 정수 합
void select(int c, int sum) {
	cout << sum << endl;

	if (max < sum) max = sum;
	
	for (auto i : A[c]) {
		// visit 체크
		select(i, sum + city[i]);
	}
}

int main() {

	int T = 0; cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 1; i <= N; i++) cin >> city[i]; // 도시 정수 입력
		
		for (int i = 1; i <= N - 1; i++) { // 도시 연결 정보 입력
			int a, b;
			cin >> a >> b;
			A[a].push_back(b); A[b].push_back(a); //  무향 그래프라 양쪽 다 기록
		}
		
		int blue_sum = 0, yellow_sum = 0;

		// 출발도시 선택
		for (int i = 1; i <= N; i++) {

			visit[i] = true; 
			select(i);// blue
			//select(j); // yellow
			
		}

	}

	return 0;
}
