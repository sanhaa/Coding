// BOJ 4949 균형잡힌 세상
// 스택
// 문장 여러개 입력
#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		char c;
		scanf("%c", &c);
		if (c == '.') break;

		vector<char> st;
		bool is_balanced = true;
		while (c!='.') {
			if (c == '(' || c == '[') {
				st.push_back(c);
			}
			else if (c == ')') {
				if (st.empty() || st.back() != '(') {
					is_balanced = false;
				}
				else st.pop_back();
			}
			else if (c == ']') {
				if (st.empty() || st.back() != '[') {
					is_balanced = false;
				}
				else st.pop_back();
			}
			scanf("%c", &c);
			if (c == '.') {
				scanf("%c", &c); // 줄바꿈 문자
				break;
			}
		}
		if (!st.empty()) is_balanced = false;
		printf("%s\n", (is_balanced ? "yes" : "no"));
	}

	return 0;
}