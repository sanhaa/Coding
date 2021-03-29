#include <iostream>
using namespace std;

const int STACK_SIZE = 10;

int stack[STACK_SIZE] = { 0, };
int top = -1;

bool isFull() {
	// == 말고 >=로 더 안전하게
	//if (top >= STACK_SIZE - 1)
	//	return true;
	//else
	//	return false;
	return (top >= STACK_SIZE - 1);
}

bool isEmpty() {
	//if (top <= 0)
	//	return true;
	//else
	//	return false;

	return (top < 0);
}

void push(int val) {
	if (isFull())
		cout << "Stack Overflow \n";
	else
		stack[++top] = val;
}

int pop() {
	if (isEmpty())
		cout << "Stack Underflow \n";

	else {
		int ret = stack[top];
		top--;
		return ret;
	}
}
// 우리가 아는 top()연산과 같음
int peek() {
	if (isEmpty())
		cout << "Stack Underflow \n";
	else
		return stack[top];
}

int main() {

	for (int i = 0; i < 13; i++) {
		push(i);
	}

	while (!isEmpty()) {
		cout << pop() << " ";
	}

	cout << endl;

	return 0;
}
