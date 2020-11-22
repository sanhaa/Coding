//10845번: 큐
#include <iostream>

using namespace std;

typedef struct QUEUE {
	int front;
	int back;
	int arr[10000] = { 0, };
}queue;

queue q;

int Empty() {
	return q.front == q.back ? 1 : 0;
}
void Push(int x) {
	//cout << "push in : " << q.back << endl;
	q.arr[q.back++] = x;
}
int Pop() {
	if (Empty()) return -1;
	//q.arr[q.front++] = 0; // pop해서 초기화 
	q.front++;
	return q.arr[q.front - 1];

}
int Front() {
	return Empty() ? -1 : q.arr[q.front];
}
int Back() {
	return Empty()? -1 : q.arr[q.back-1];
}
int Size() {
	if (Empty()) return 0;
	return q.back - q.front;
}


int main() {
	int N = 0;
	scanf("%d\n", &N);

	q.front = 0;
	q.back = 0;

	string cmd = "";
	while (N--) {
		cmd = "";
		cin >> cmd;
		if (cmd == "push") {
			int x = 0;
			cin >> x;
			Push(x);
		}
		else if (cmd == "pop") cout << Pop() << endl;
		else if (cmd == "front") cout << Front() << endl;
		else if (cmd == "back") cout << Back() << endl;
		else if (cmd == "size") cout << Size() << endl;
		else if (cmd == "empty") cout << Empty() << endl;

	}
}