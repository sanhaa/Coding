// Heap 구현
// Priority Queue 대신 사용할 수 있다.
#include <iostream>
using namespace std;

const int HEAP_SIZE = 10;
int heap[HEAP_SIZE] = { 0, };
int heapCount = 0; // 1부터 시작, 현재 노드 개수

void push(int value) {
	heap[++heapCount] = value; // 무조건 마지막 leaf노드에 추가
	int child = heapCount; // 추가된 노드의 인덱스
	int parent = child/2; // 부모 = 자식/2

	while (parent > 0 && heap[parent] > heap[child]) {
		// 더 작은 값을 위로 올려야 한다.
		// parent, child swap
		//int tmp = heap[parent];
		//heap[parent] = heap[child];
		//heap[child] - tmp;
		swap(heap[parent], heap[child]);

		child = parent;
		parent = child/2;
	}
	cout << "pushed : " << value << endl;
}

// PQ로 운영하는 경우 extractMin(), extractMax() 이름 사용
int pop() { // -> extractMin()
	int parent = 1; // root 노드 삭제
	int ret = heap[parent];
	// 마지막 leaf -> root채우기
	heap[parent] = heap[heapCount];
	heap[heapCount] = 0; --heapCount; // 개수 하나 줄이기

	int child = parent * 2; // left
	if (child + 1 <= heapCount) {
		// 오른쪽 자식이 존재하면 크기 비교해서 어느 자식이 swap 될건지 찾기(더 작은 자식이 위로 올라감)
		child = heap[child] < heap[child + 1] ? child : child + 1;
	}

	while (child <= heapCount && heap[parent] > heap[child]) {
		// parent, child swap
		//int tmp = heap[parent];
		//heap[parent] = heap[child];
		//heap[child] - tmp;
		swap(heap[parent], heap[child]);

		child = parent;
		parent = child / 2;
		if (child + 1 <= heapCount) {
			child = heap[child] < heap[child + 1] ? child : child + 1;
		}
	}

	return ret;
}

void print_heap() {
	cout << endl;
	cout << "Heap -----" << endl;
	//int pow2[] = { 1, 2, 4, 8, 16, 32, 64 };
	for (int i = 1; i <= heapCount; i++) {
		cout << heap[i] << " ";
	}
	cout << endl << "----------" << endl<<endl;
}

int main() {
	push(20);
	push(17);
	push(19);
	push(4);
	push(13);
	push(11);
	push(23);

	print_heap();
	
	cout << "poped : "<< pop() << endl;

	print_heap();

	return 0;
}
