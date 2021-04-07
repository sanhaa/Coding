#include <iostream>
using namespace std;

const int N_MAX = 50001;
const int Q_MAX = 200001;

int leaf[N_MAX] = { 0, };
int seg_start[Q_MAX] = { 0, };
int seg_end[Q_MAX] = { 0, };

int max(int a, int b) {
	return a > b ? a : b;
}

struct SegmentTree {
	int* t;
	int size;

	SegmentTree(int*a, int n) {
		size = n;
		t = new int[2 * n];

		t[0] = 0;
		for (int i = 0; i < n; i++) {
			t[n + i] = a[i];
		}
		for (int i = n - 1; i > 0; i--) { 
			cout << t[i << 1]<< ", "<< t[i << 1 | 1] << endl;
			t[i] = max(t[i << 1], t[i << 1 | 1]); // left, right 자식(*2) 값 중 큰 것
		}
	}
	int query(int l, int r) {
		int ret = 0;
		for (l += size, r += size; l < r; l >> 1, r >> 1) {
			if (l & 1) ret = max(ret, t[l++]); // l이 홀수면
			if (r & 1) ret = max(ret, t[--r]); // r이 홀수면
		}
		return ret;
	}
};

int main() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> leaf[i];
	}

	for (int i = 0; i < Q; i++) {
		cin >> seg_start[i] >> seg_end[i];
	}
	SegmentTree Tree = SegmentTree(leaf, N);

	cout << "Tree size : " << Tree.size << endl;

	for (int i = 1; i < 2 * N; i++) {
		cout << Tree.t[i] << " ";
	}
	cout << endl;

	cout << Tree.query(1, 7) << endl;

	return 0;
}
