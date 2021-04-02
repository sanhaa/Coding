#include <iostream>

using namespace std;

int arr[] = { 1, 2, 3, 4, 5 };
int p[] = { 0, };

void printArray(int* arr, int n) {
	
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	cout << endl;
}

void perm_recursive(int k, int n) {
	if (k == n) {
		// npr에서 r == n
		printArray(arr, n);
	}
	else{
		for (int i = k; i < n; i++) {
			swap(arr[i], arr[k]);
			perm_recursive(k + 1, n);
			swap(arr[i], arr[k]); // 원래대로 되돌림 = 순서 때문에
		}
	}
}
 
//nPr
void nPr(int n, int r, int q) {
	if (r==0) {
		printArray(p, q);

	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[n - 1]);
			p[r - 1] = arr[n - 1]; // q는 r의 백업본
			nPr(n - 1, r - 1, q);
			swap(arr[i], arr[n - 1]);
		}
	}
}

//nPIr
void nPIr(int n, int r, int q) {
	if (r == 0) {
		printArray(p, q);
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[n - 1]);
			p[r - 1] = arr[n - 1]; // q는 r의 백업본
			nPr(n, r - 1, q); // nPI(r-1)
			swap(arr[i], arr[n - 1]);
		}
	}
}

int main() {
	printf("순열 - 재귀 (5P3)\n");
	perm_recursive(0, 3);

	printf("순열 - 점화식(5P3)\n");
	nPr(3, 3, 3);

	printf("중복순열 - 점화식");
	nPIr(3, 3, 3);
}
