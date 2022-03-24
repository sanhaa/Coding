#include <iostream>

using namespace std;

const int STACK_SIZE = 200;
const char sharp = '#';

void calculate(char c);

int priority(char a) {
	if (a == '+' || a == '-') return 1;
	else if (a == '*' || a == '/') return 2;
	else if (a == '(') return 0;
	else {
		cout << "unexpected operation" << endl;
		return -1;
	}
}

class stack {
public:
	int top = -1;
	int arr[200] = { 0, };

	bool is_empty();
	void push(int val);
	void pop(); // arr[top] 제거
	int peek(); // arr[top] 반환
};

stack opers;
stack cal;

bool stack::is_empty(){
	if (top < 0) return true;
	else return false;
}

void stack::push(int val) {
	arr[++top] = val;
}

void stack::pop() {
	char top_val = arr[top];
	arr[top] = 0;
	top -= 1;
}

int stack::peek() {
	if (top == -1) cout << "stack is empty\n";
	else 
		return arr[top];
}

void calculate(char op) {
	int a = cal.peek();
	cal.pop();
	int b = cal.peek();
	cal.pop();
	int ab = 0;
	if (op == '+')
		ab = a + b;
	else if (op == '-')
		ab = a - b;
	else if (op == '*')
		ab = a * b;
	else if (op == '/')
		ab = a / b;
	else
		cout << "not expected operation" << endl;

	cal.push(ab);
}

int main() {
	int T = 10;

	freopen("input.txt", "r", stdin);

	for (int t = 1; t <= T; t++) {
		int len = 0;
		char ori_form[STACK_SIZE] = { 0, };

		cin >> len;
		scanf("%s", ori_form);

		for (char c : ori_form) {
			if (c == 0) break;
			int ic = c - '0';
			if (ic <= 9 && ic >= 0) { // 숫자면
				cal.push(ic);
			}
			else if (c == '(') {
				opers.push(c);
			}
			else if (c == ')') {
				while (1) { // ( 찾을때까지 pop
					char top_val = (char)opers.peek();
					if (top_val == '(') {
						opers.pop();
						break;
					}
					calculate(top_val); // pop으로 연산자 꺼낼 때마다 계산
					opers.pop();
				}
			}
			else { // 사칙 연산
				int pri_c = priority(c);
				int pri_t = priority(opers.peek());

				if (opers.is_empty()) opers.push(c);
				else if (pri_c > pri_t) {
					opers.push(c);
				}
				else {
					while (pri_c <= pri_t) {
						if (opers.is_empty()) break;
						calculate(opers.peek()); // pop으로 연산자 꺼낼 때마다 계산
						opers.pop();
						pri_t = priority(opers.peek());
					}
					opers.push(c);
				}
			}
		}

		// for 문 탈출했는데 스택이 비어있지 않으면 비워주기
		while (!opers.is_empty()) {
			calculate(opers.peek()); // pop으로 연산자 꺼낼 때마다 계산
			opers.pop();
		}

		cout<<sharp<<t<<" " << cal.peek() << endl;
	}
}
