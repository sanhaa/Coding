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
