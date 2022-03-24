/*
모의 시험 : 디렉토리 카운트

최대 자식 개수 : 256
최대 트리 높이 : 4096
최대 노드 개수 : 256 * 4096
*/
#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

#define sharp '#'

//const int MAX_H = 4100; // 높이 제한 없음
const int MAX_CHILD = 500;
const int MAX_N = 1000000 + 100; // 100 만
		
vector<int> Tree[MAX_N];

// node: 해당 node 기준 하위 노드 탐색
// 하위 노드 중 번호가 node보다 작은 것의 개수 return
long long int travel(int node) {
	long long int ret = 0; // cnt

	stack<int> st; st.push(node);

	while (!st.empty()) {
		int now = st.top(); st.pop();
			
		for (int child : Tree[now]) { // now를 parent로 하는 노드 
			// 자식들 방문
			if (node > child) {
				ret += 1;
			}
			st.push(child);
		}
	}

	return ret;
}

// for test
void print_Tree() {
	cout << "Tree print ----" << endl;
	for (int i = 0; i < MAX_CHILD;i++) {
		if (Tree[i].size() == 0) continue;
		cout << i << ": ";
		for (int j = 0; j < Tree[i].size();j++) {
			cout << Tree[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	clock_t start, s, end, e;
	start = clock();

	int T = 0; cin >> T; // test case 
	for (int t = 1;t <= T;t++) {
		s = clock();

		// 초기화
		for (int i = 0;i < MAX_N;i++)  Tree[i].clear();
		
		long long int ans = 0; // 총 카운트 합
		int N = 0, root = 0;

		/*  input  */
		cin >> N >> root;
		
		for (int i = 0; i < N - 1;i++) {
			// 상-하위 디렉토리 연결 정보
			int parent = 0, child = 0;
			cin >> parent >> child;
			Tree[parent].push_back(child);
		}

		// 1 ~ N 노드 기준으로 하위 노드 탐색 및 카운트
		for (int i = 1;i <= N;i++) { 
			ans += travel(i);
			// cout << i<<" : "<<ans << endl;
		}

		e = clock();
		
		cout << sharp << t << " " << ans;
		printf(" ------ %.3f sec\n", float(e - s)/1000.0);
	}

	end = clock();
	 
	printf("total : %.3f sec\n", float(end - start)/1000.0);

	return 0;
}
