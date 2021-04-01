// S_1248 
// V가 100개면 1~ 100까지의 정점 번호만 쓰인다
#include <iostream>
#include <vector>
using namespace std;

const char sharp = '#';

const int TREE_SIZE = 10000;
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

int get_level(int v) {
	if (v < 1) return 0;

	int l = get_level(Left[v]);
	int r = get_level(Right[v]);

	if (l > r) return l + 1;
	return r + 1;
}

int main() {
	freopen("input.txt", "r", stdin);

	int T = 0;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		fill_n(Left, TREE_SIZE, 0);
		fill_n(Right, TREE_SIZE, 0);
		fill_n(Parent, TREE_SIZE, 0);

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

		cout << get_level(v1) << endl;

		//print1();
		//print2();
		//print3();

		// LCA 어떻게 찾지
	//	vector<int> pp1;
	//	vector<int> pp2;
	//	int p1 = v1; // 5
	//	int p2 = v2; // 6

	//	int LCA = p1;

	//	pp1.push_back(p1);
	//	pp2.push_back(p2);

	//	while (p1 != p2 && p1>=1 && p2>=1) {
	//		p1 = Parent[p1];
	//		p2 = Parent[p2];
	//		pp1.push_back(p1);
	//		pp2.push_back(p2);
	//	}

	//	for (int i = 0; i < pp1.size(); i++) {
	//		for (int j = 0; j < pp2.size(); j++) {
	//			if (pp1[i] == pp2[j]) LCA = pp1[i];
	//		}
	//	}
	//	cout << sharp<<t<<" "<< LCA << endl;
	}
}
