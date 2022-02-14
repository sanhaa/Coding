// S_1248 
// V가 100개면 1~ 100까지의 정점 번호만 쓰인다
#include <iostream>
#include <vector>
using namespace std;

const char sharp = '#';

const int TREE_SIZE = 10001; // 10001
int Left[TREE_SIZE] = { 0, };
int Right[TREE_SIZE] = { 0, };
int Parent[TREE_SIZE] = { 0, };

void print1() {
	cout << "Left : ";
	for (int i = 0; i < TREE_SIZE; i++) {
		//if (Left[i] == 0) continue;
		cout << Left[i] << " ";
	}
	cout << endl;
}

void print2() {
	cout << "Right : ";
	for (int i = 0; i < TREE_SIZE; i++) {
		//if (Right[i] == 0) continue;
		cout << Right[i] << " ";
	}
	cout << endl;
}

void print3() {
	cout << "Parent : ";
	for (int i = 0; i < TREE_SIZE; i++) {
		//if (Parent[i] == 0) continue;
		cout << Parent[i] << " ";
	}
	cout << endl;
}

int childs = 0;

void preorder(int node, int count) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (node == 0) return;
	childs++;
	//cout << node; // v
	preorder(Left[node], count+1); // L
	preorder(Right[node], count+1); // R
}

int main() {

	freopen("input.txt", "r", stdin);

	int T = 0;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		// 테케 반복 초기화
		fill_n(Left, TREE_SIZE, 0);
		fill_n(Right, TREE_SIZE, 0);
		fill_n(Parent, TREE_SIZE, 0);
		childs = 0;

		int V, E, v1, v2;
		cin >> V >> E >> v1 >> v2;

		for (int i = 0; i < E; i++) {
			int parent, child;
			cin >> parent >> child;

			// for check
			if (parent > V || child > V) {
				cout << "vertex num is over\n";
				return 0;
			}

			if (Left[parent] == 0) // 왼쪽 자식이 아직 없으면
				Left[parent] = child;
			else
				Right[parent] = child;

			Parent[child] = parent;
		}

		//print1();
		//print2();
		//print3();

		// LCA 찾기
		bool visit[TREE_SIZE] = { 0, };
		while (v1 != 0) {
			visit[v1] = 1;
			v1 = Parent[v1];
		}
		while (!visit[v2]) {
			v2 = Parent[v2];
		}
		// subtree 크기, 자식노드 개수 찾기
		preorder(v2, 0);
		cout << sharp<<t<<" "<< v2 <<" "<<childs<< endl;
	}
}
