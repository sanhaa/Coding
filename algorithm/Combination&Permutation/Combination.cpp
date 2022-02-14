#include <iostream>

using namespace std;

int arr[4] = { 1, 2, 3, 4 };
int t[] = { 0, };

void print_array(int t[], int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", t[i]);
	}
	printf("}\n");
}

// nCr = (n-1)C(r-1)  + (n-1)Cr
// q는 숫자 개수
void nCr(int n, int r, int q) {
	if (r == 0) {
		print_array(t, q);
	}
	else if (n < r) return;
	else {
		t[r - 1] = arr[n - 1];
		nCr(n - 1, r - 1, q);
		nCr(n - 1, r, q);
	}
}

// nHr = nH(r-1)  + (n-1)Hr
void nHr(int n, int r, int q) {
	if (r == 0) {
		print_array(t, q);
	}
	else if (n < 1) return;
	else {
		t[r - 1] = arr[n - 1];
		nHr(n, r - 1, q);
		nHr(n - 1, r, q);
	}
}

int main() {

	printf("\n조합 \n");
	nCr(4, 3, 3);

	printf("\n중복 조합\n");
	nHr(4, 3, 3);

	return 0;
}
