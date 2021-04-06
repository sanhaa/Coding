#include <iostream>
using namespace std;
// + 43 - 45 / 47 * 42
const int TREE_SIZE = 1001;
const char sharp = '#';

int Tree[TREE_SIZE] = { 0, };
int Left[TREE_SIZE] = { 0, };
int Right[TREE_SIZE] = { 0, };

int N = 0;

int find_node(int num) {
	if (Tree[num] != 0) return true;
	else return false;
}

void print_tree() {
	cout << "N is " << N << endl;
	for (int i = 1; i <= N; i++) {
		printf("%c ", Tree[i]);
	}
	cout << endl;
}

// 후위 순회로 계산하기
void post_order(int node) {
	if (node < 1 || node > N) return;
	if (Tree[node] == 0 || Left[node] == 0 || Right[node] == 0) return; // 어떤 노드에 data가 없으면

	post_order(Left[node]); // 왼쪽 자식 순회
	post_order(Right[node]); // 오른쪽 자식 순회
	//printf("%d ", Tree[node]);

	if (Tree[node] < 48) {
		int l = Tree[Left[node]];
		int r = Tree[Right[node]];

		switch (Tree[node]) {
		case 43:
			Tree[node] = l + r; break;
		case 45:
			Tree[node] = l - r; break;
		case 47:
			Tree[node] = l / r; break;
		case 42:
			Tree[node] = l * r; break;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	int T = 10; // 10
	for (int t = 1; t <= T; t++) {
		// 테케 반복 변수 초기화
		fill_n(Tree, TREE_SIZE, 0);
		fill_n(Left, TREE_SIZE, 0);
		fill_n(Right, TREE_SIZE, 0);
		N = 0;
		scanf("%d", &N);

		for (int k = 0; k < N; k++) {
			int n = 0;
			char data[TREE_SIZE] = { 0, };

			scanf("%d %s", &n, data);
			// 노드 데이터의 첫값으로 연산자와 숫자를 구분
			if (data[0] == '+' || data[0] == '-' || data[0] == '*' || data[0] == '/') {

				int left, right;
				Tree[n] = data[0];
				//cout << n << "th value: " << Tree[n] << endl;

				scanf("%d %d", &left, &right);
				Left[n] = left;
				Right[n] = right;
			}

			else { // data는 숫자
				int num = atoi(data);
				Tree[n] = num;
				//cout << n << "th value: " << Tree[n] << endl;
			}
		}

		post_order(1);
		cout << sharp<<t<<" " << Tree[1] << endl;
	}

	return 0;
}
