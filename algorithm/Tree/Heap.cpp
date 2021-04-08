// Heap 구현
// Priority Queue 대신 사용할 수 있다.
#include <iostream>
using namespace std;

const int HEAP_SIZE = 10;
int heap[HEAP_SIZE] = { 0, };
int heapCount = 0; // 1부터 시작

void push(int value) {
	heap[++heapCount] = value; // 무조건 마지막 leaf노드에 추가
	int child = heapCount;
	int parent = child >> 1;

	while (parent > 0 && heap[parent] > heap[child]) {
		// parent, child swap
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] - tmp;

		child = parent;
		parent = child >> 1;

	}
}
// Pq로 운영하는 경우 extractMin(), extractMax() 이름 사용
int pop() { // -> extractMin()
	int parent = 1; // root 노드 삭제
	int ret = heap[parent];
	// 마지막 leaf -> root채우기
	heap[parent] = heap[heapCount];
	heap[heapCount--] = 0;

	int child = 2 * parent;
	if (child + 1 <= heapCount) {
		// 오른쪽 자식이 존재하면
		child = heap[child] < heap[child + 1] ? heap[child] : heap[child + 1];
	}

	while (child <= heapCount && heap[parent] > heap[child]) {
		// parent, child swap
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] - tmp;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapCount) {
			child = heap[child] < heap[child + 1] ? heap[child] : heap[child + 1];
		}
	}

	return ret;
}

void print_heap() {
	int pow2[] = { 1, 2, 4, 8, 16, 32, 64 };
	for (int i = 1; i < heapCount; i++) {
		cout << heap[i] << " ";
	}
}

int main() {
	push(20);
	push(17);
	push(19);
	push(4);
	push(13);
	push(11);
	push(23);

	//print_heap();

	cout << pop() << endl << endl;

	print_heap();

	return 0;
}
