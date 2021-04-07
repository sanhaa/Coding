// 최소 신장 트리 (알고리즘 개론 )
#include <iostream>
#include <cstdio>
#include <fstream>
#include <queue>

#define INF 1000000;
using namespace std;

struct V{
	int idx;
	int dist = INF;
	int parent = 0;
};

struct cmp {
	bool operator()(V a, V b) {
		return a.dist > b.dist;
	}
};

int main(int argc, char* argv[]) {

//	ifstream fin;
//	fin.open(argv[1]);
	int n, m;
//	fin >> n >> m;
	cin >> n >> m;
	bool *visit = new bool(n);
	int **arr = new int*[n+1];
	for (int i = 0;i < n+1; i++) {
		arr[i] = new int[n+1]();
	//	arr[i] = { 0, };
	}

	int a, b, c;
	for (int i = 0;i < m;i++) {
		//fin >> a >> b >> c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}
	
	V *list = new V[n];

	//prim algorithm start

	visit[1] = true;
	list[1].dist = 0;
	list[1].parent = 0;
	priority_queue<V, vector<V>, cmp> pq;

	//시작이 1일때 인접한 vertex들 큐에 넣기, updating
	for(int i=0; i<n+1; i++) {
		if (arr[1][i] == 0)	continue;
		list[i].idx = i;
		list[i].dist = arr[1][i];
		list[i].parent = 1;
		pq.push(list[i]);
	}
	int res = 0;
	while (!pq.empty()) {
		V now = list[pq.top().idx];
		pq.pop();
		visit[now.idx] = true;
		res += now.dist;
		for (int i = 0;i < n+1;i++) {
			if (arr[now.idx][i] == 0)	continue;
			list[i].idx = i;
			if (list[i].dist > arr[now.idx][i] && visit[i]==false) {
				list[i].dist = arr[now.idx][i];
				list[i].parent = now.idx;
				pq.push(list[i]);
			}
		}
	}
	cout << res << endl;
	//ofstream fout;
	//fout.open(argv[2]);
	//fout << res <<endl;

	//fin.close();
	//fout.close();

}
