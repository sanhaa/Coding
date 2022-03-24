 
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
 
//struct SegmentTree {
//  int* t = 0;
//  int size;
//
//  SegmentTree() {}
//  SegmentTree(int*a, int n) {
//      size = n;
//      t = new int[4*N_MAX]; // 2n-1 만큼
//      fill_n(t, 4 * N_MAX, 0);
//      init(a, 1, 1, n);
//  }
//
//  int init(int* a, int index, int start, int end) {
//      if (start == end) return t[index] = a[start];
//      else {
//          return t[index] = max(init(a, index * 2, start, (start + end) / 2),
//              init(a, index * 2 + 1, (start + end) / 2 + 1, end));
//      }
//  }
//
//  // 총 구간은 start ~ end, 입력된 범위는 left ~ right
//  int query(int index, int start, int end, int left, int right) {
//      if (left > end || right < start) return 0;
//      if (left <= start && right >= end) return t[index];
//      //int half = (start + end)/2;
//
//      return max(query(index * 2, start, (start + end) / 2, left, right),
//          query(index * 2 + 1, (start + end) / 2 + 1, end, left, right));
//  }
//};
 
 
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
    //SegmentTree Tree = SegmentTree(leaf, N);
    init(leaf, 1, 1, N);
 
    //cout << "Tree size : " << N<< endl;
    //cout <<"Tree ------ ";
    //for (int i = 1; i <= 4*N; i++) {
    //  cout << Tree[i] << " ";
    //}
    //cout << endl;
 
    for (int i = 0; i < Q; i++) {
        int left, right;
        cin >> left >> right;
        cout << query(1, 1, N, left, right) << "\n";
    }
 
    return 0;
}
