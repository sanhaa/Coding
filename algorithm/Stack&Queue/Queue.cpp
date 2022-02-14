// 선형 큐 구현
// QUEUE_SIZE 엄청 크게 잡고 써라
// 코테에서는 원형 큐 말고 이거 써라
#include <iostream>
using namespace std;

const int QUEUE_SIZE = 10;
int q[QUEUE_SIZE] = { 0, };
int front = -1;
int rear = -1;

bool isFull() {
	if (rear >= QUEUE_SIZE - 1)
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
	else
		q[++rear] = val;
}

int deQueue() {
	if (isEmpty())
		cout << "Queue Underflow \n";
	else {
		//return q[++front];
		int ret = q[++front];
		return ret;
	}
}

int Qpeek() {
	if (isEmpty())
		cout << "Queue Underflow \n";
	else
		return q[front];
}

int main() {

	for (int i = 1; i <= 12; i++) {
		enQueue(i);
	} // Queue Overflow 두번

	while (!isEmpty()) {
		cout << deQueue() << " ";
	}
	cout << endl;

	// 0~9는 잘 들어가지만 선형 큐이므로
	// 실제로 모두 deQueue했지만 front == rear가 되어 꽉 찼다고 판단
	enQueue(50); // Queue Overflow

	return 0;
}
