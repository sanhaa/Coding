// 원형 큐 구현
// 선형 큐보다 공간복잡도에 강점이 있지만
// 매번 mod 연산을 해야하는 것이 단점
#include <iostream>
using namespace std;

const int QUEUE_SIZE = 10;
int q[QUEUE_SIZE] = { 0, };
int front = 0;
int rear = 0;

bool isFull() {
	if ((rear+1) % QUEUE_SIZE == front)
		return true;
	else
		return false;
}

bool isEmpty() {
	if (front == rear)
		return true;
	else
		return false;
}

void enQueue(int val) {
	if (isFull())
		cout << "Queue Overflow \n";
	else {
		rear = (rear + 1) % QUEUE_SIZE;
		q[rear] = val;
	}
}

int deQueue() {
	if (isEmpty())
		cout << "Queue Underflow \n";
	else {
		front = (front + 1) % QUEUE_SIZE;
		int ret = q[front];
		q[front] = 0; // 초기화
		return ret;
	}
}

int Qpeek() {
	if (isEmpty())
		cout << "Queue Underflow \n";
	else
		return q[(front+1)%QUEUE_SIZE];
}

int main() {
	// 큐 사이즈가 10이지만 empty 체크를 위해 한칸 비워야 하기 때문에 총 넣을 수 있는 데이터는 9개
	for (int i = 1; i <= 12; i++) {
		enQueue(i);
	} //  ( Queue Overflow ) 3번 

	while (!isEmpty()) {
		cout << deQueue() << " ";
	}
	cout << endl; // 1 2 3 4 5 6 7 8 9

	// 원형 큐는 포화상태를 잘 인식하므로 
	// 10개 넣었다가 10개 빼고 다시 넣어도 
	enQueue(50); 

	while (!isEmpty()) {
		cout << deQueue() << " ";
	}
	cout << endl; // 50

	return 0;
}
