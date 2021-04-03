// J_1440 최소공통조상 문제
// LCA 구하는 두가지 방법
#include <iostream>
using namespace std;

const int MAX_N = 10001;
int Parent[MAX_N] = { 0, }; // 조상 찾는거라 부모정보만 있으면

// 먼저 첫번째 노드의 조상을 저장하고
// 저장된 조상이랑 같은 두번째 노드의 조상이 있는지 찾는다
int LCA(int n1, int n2) {
	int checked[MAX_N] = { 0, };
	while (n1 != 0) {
		checked[n1] = 1;
		n1 = Parent[n1];
	}
	while (checked[n2] == 0) {
		n2 = Parent[n2];
	}
	return n2;
}

int height_of(int n) {
	int h = 0;
	while (n != 0) {
		h++;
		n = Parent[n];
	}
	return h;
}

// 높이 계산해서 높이를 맞춰가며 조상을 찾는다
int LCA2(int n1, int n2) {
	int h1 = height_of(n1);
	int h2 = height_of(n2);
	int h = h1 - h2;
	if (h > 0) {
		while (h--) {
			n1 = Parent[n1];
		}
	}
	else if (h < 0) {
		while (h++ == 0) {
			n2 = Parent[n2];
		}
	}
	if (h == 0) {
		while (n1 != n2) {
			n1 = Parent[n1];
			n2 = Parent[n2];
		}
	}
	return n2;
}

int main() {
	int N = 0; // 노드의 수
	int n1, n2; // 공통조상을 찾을 두 노드
	cin >> N;

	
	for (int i = 0;i < N - 1;i++) {
		int parent, child;
		cin >> parent >> child;
		Parent[child] = parent;
	}
	cin >> n1 >> n2;

	
	cout<<LCA(n1, n2)<<endl;
	//cout << LCA2(n1, n2)<< endl;

	return 0;
}
