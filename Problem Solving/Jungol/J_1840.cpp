// J_1840 구간 최솟값1
// 세그먼트 트리 구현
#include <iostream>
using namespace std;

const int N_MAX = 50001;
const int Q_MAX = 200001;
const int TREE_SIZE = 4 * N_MAX;

int Tree[TREE_SIZE] = { 0, };
int leaf[N_MAX] = { 0, };

int max(int a, int b) {
	return a > b ? a : b;
}

int init(int* a, int index, int start, int end) {
	if (start == end) return Tree[index] = a[start];
	else {
		return Tree[index] = max(init(a, index * 2, start, (start + end) / 2),
			init(a, index * 2 + 1, (start + end) / 2 + 1, end));
	}
}

int query(int index, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return Tree[index];
	//int half = (start + end)/2;

	return max(query(index * 2, start, (start + end) / 2, left, right),
		query(index * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int N, Q;
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> leaf[i];
	}

	init(leaf, 1, 1, N);

	for (int i = 0; i < Q; i++) {
		int left, right;
		cin >> left >> right;
		cout << query(1, 1, N, left, right) << "\n";
	}

	return 0;
}
