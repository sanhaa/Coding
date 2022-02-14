// 양팔저울과 추 7개(1g, 3g, 9, 27g, 81g, 243g, 729g)가 있다
// 어떤 물체의 무게 N을 입력받아서 물체와 추7개로 양팔저울의 평형을 만들수 있는지 찾는데
// 평형이 될 때 왼쪽에 있는 추들과 오른쪽에 있는 추들의 무게를 출력한다.(작은 무게부터 순서대로 출력)
// 왼쪽과 오른쪽 추들을 구분하기 위해 사이에 출력값들 사이에 0을 넣는다.
// input:  25
// output: 25 3 0 3 27
#include <iostream>

using namespace std;

// enum -------------
enum USAGE {
	NONE, LEFT, RIGHT
};

int weight[7] = { 1, 3, 9, 27, 81, 243, 729 };
int Usage[7] = { 0, }; // 7개의 추가 left에 올려져 있으면 1, right 2 아니면 0

// k 는 레벨, left, right에 올려진 무게합
int balance(int k, int left, int right) {
	if (k > 7) return 0;
	if (left == right) return 1;

	Usage[k] = LEFT;
	
	if (balance(k + 1, left + weight[k], right) == 1) return 1;

	Usage[k] = RIGHT;
	if (balance(k + 1, left, right + weight[k]) == 1) return 1;

	Usage[k] = NONE;
	if (balance(k + 1, left, right) == 1) return 1;

	return 0; // 그 어디서도 반환값이 1이 아니면 답이 없다
}

int main() {
	int w = 0;
	scanf("%d", &w);

	int res = balance(0, w, 0);

	if (res) {
		printf("%d ", w);
		for (int i = LEFT; i <= RIGHT; i++) {
			for (int j = 0; j < 7; j++) {
				if (Usage[j] == i) {
					cout << weight[j] << " ";
				}
			}
			if (i == LEFT) cout << "0 ";
		}
	}
	else { // 못재는 경우
		printf("-1");
	}

	cout << endl;

	return 0;
}
