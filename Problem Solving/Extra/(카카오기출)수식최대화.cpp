/*
연산자 종류 : + - *
우선순위를 맘대로 설정하여 가장 높은 결과 리턴하기
항상 3! 즉 6개의 경우의 수가 존재
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define ADD '+'
#define MINUS '-'
#define MULT '*'

int to_idx(char c) {
	switch (c) {
	case ADD:
		return 0;
	case MINUS:
		return 1;
	case MULT:
		return 2;
	}
	return -1;
}

int priority[][3] = { 
	{1, 2, 3}, {1, 3, 2},
	{2, 1, 3}, {2, 3, 1},
	{3, 1, 2}, {3, 2, 1}
};

long long int calculate(int pi, string expression) {
	stack<long long int> nums; // 중위표기식 표현 계산을 위한 스택
	stack<char> opers; 

	string str;

	for (char c : expression) {
		if (c == '+' || c == '-' || c == '*') {
			if (str != "") { // 숫자가 완성되었으면 push
				nums.push(stol(str));
			}
			if (opers.empty() == true) opers.push(c);

			// 우선순위 검사해서 
			// 나보다 우선순위 작거나 같으면 pop
			char top = ( opers.top());
			if (priority[pi][to_idx(top)] < priority[pi][to_idx(c)]) {
				opers.pop();

				long long int a = nums.top(); nums.pop();
				long long int b = nums.top(); nums.pop();

				switch (top) {
				case ADD:
					nums.push(a + b); break;
				case MINUS:
					nums.push(a - b); break;
				case MULT:
					nums.push(a*b); break;
				}
			}
			opers.push(c);
		}
		else { // 숫자만들기
			str += c;
		}
	}
}

long long solution(string expression) {
	long long answer = 0;

	for (int i = 0; i < 6; i++) {
		calculate(i, expression);
	}


	return answer;
}

int main() {
	string exp = "100 - 200*300-500+20";
	solution(exp);

	return 0;
}
