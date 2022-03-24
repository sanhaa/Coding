#include <iostream>
using namespace std;

const int LIST_SIZE = 4001;
const int COMM_SIZE = 501;

int list[LIST_SIZE] = { 0, };
int len = 0;

void Insert(int x, int y, int* s) {

	// x+1 부터 x+1+y까지 (순서반대로) 뒤로 한칸씩 이동
	for (int k = len - 1; k >= x; k--) {
		list[k + y] = list[k];
	}
	for (int i = 0; i < y; i++) {
		list[x + i] = s[i];
		len++;
	}
}

void Delete(int x, int y) {
	for (int i = x+1; i < x+y+1; i++) {

		list[i] = list[i+y];
	
		list[i+y] = -1;
		len--;
	}
}

void print_list() {
	int idx = -1;
	while (list[++idx] != -1) {
		cout << list[idx] << " ";
	}
	cout << endl;
}

int main() {

	//freopen("input.txt", "r", stdin);

	int T = 1;
	for (int t = 1; t <= T; t++) {
		fill_n(list, LIST_SIZE, -1); // -1로 초기화
		int N = 0, M = 0;

		cin >> N;
		len = N;
		for (int n = 0; n < N; n++) {
			int code = 0;
			cin >> code;
			list[n] = code;
		}
		cin >> M;
		for (int m = 0; m < M; m++) {
			// 명령어 input
			char type = 0;
			int x = 0, y = 0;
			int s[LIST_SIZE] = { 0, };

			cin >> type;
			switch (type) {
			case 'I':
				scanf("%d %d", &x, &y);
				for (int i = 0; i < y; i++) scanf("%d", &s[i]);
				// insert
				Insert(x, y, s);
				break;

			case 'D':
				scanf("%d %d", &x, &y);
				// delete
				Delete(x, y);
				break;

			case 'A':
				scanf("%d", &y);
				for (int i = 0; i < y; i++) scanf("%s", s[i]);
				// append
				break;

			}
		}

		printf("#%d ", t);
        
		for (int i = 0; i < 10; i++) {
			printf("%d ", list[i]);
		}
		cout << endl; 
	}
}
