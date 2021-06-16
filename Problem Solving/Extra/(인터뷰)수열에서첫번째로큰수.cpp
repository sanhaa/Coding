// etc. 수열에서 자기보다 큰 첫번째 수 찾기
// ex. [4,2,6,7,9,1]
// print: (4,6) (2,6) (6,7) (7,9) (9,0) (1,0)
// ?? 순서대로 출력하기
#include <iostream>

using namespace std;

int main() {
	int N = 0; cin >> N;
	int ans[100] = { 0, }; int idx = 0;
	int st[100] = { 0, };
	int top = -1;

	int num = 0;
	for (int i = 0;i < N;i++) {
		cin >> num;

		while (top >= 0 && num > st[top]) {
			cout << "( "<< st[top] << ", " << num <<" )" << endl;
			st[top] = 0; top -= 1; // stack pop
		}

		st[++top] = num; // stack push
	}

	while (top>=0) { // stack에 남아있는거는 자기보다 큰 수가 없는거, 0으로 출력
		cout << "( " << st[top] << ", 0 )" << endl; top--;
	}

	return 0;
}
