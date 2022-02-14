#include <iostream>
using namespace std;

const int TREE_SIZE = 101;
const char sharp = '#';
char tree[TREE_SIZE] = { 0, }; // 알파벳 담을 트리
int V;

// charcter c 를 가진 정점이 있는가
int findNode(char c) {
	for (int i = 1; i < TREE_SIZE; i++) {
		if (tree[i] == c) {
			return i;
		}
	}
	return -1;
}

// node = node number
void inorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return; // 해당 자리에 노드 없는 경우

	inorder(node << 1); // L
	cout << tree[node]; // v
	inorder((node << 1) + 1); // node*2 +1 R
}

void print_tree() {
	for (int i = 1; i < TREE_SIZE; i++) {
		cout << tree[i];
	}
	cout << endl;
}


int main() {

	int T = 10; // 10
	for (int t = 1; t <= T; t++) {
		// 반복시 초기화
		fill_n(tree, TREE_SIZE, 0);
		V = 0;

		// 테스트 케이스만큼 반복
		cin >> V;

		int num = 0; // 정점 번호
		char C = 0; // 정점에 있는 알파벳
		int left = 0, right = 0; // 왼쪽, 오른쪽 자식 정점 번호

		// input 3개짜리
		for (int i = 0; i < (V - 1) / 2; i++) {
			cin >> num >> C >> left >> right;
			tree[num] = C;
			// left = num *2, right = num*2+1
		}
		// 2
		for (int i = 0; i < (V + 1) % 2; i++) {
			cin >> num >> C >> left;
			tree[num] = C;
		}
		// 1
		for (int i = 0; i < (V + 1) / 2; i++) {
			cin >> num >> C;
			tree[num] = C;
		}

		//print_tree();
		cout << sharp<< t << " ";
		inorder(1);
		cout << endl;
	}
    return 0;
}
