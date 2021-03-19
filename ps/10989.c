#include <stdio.h>

#include <stdio.h>

#define MAX_N 10001

int main() {
	int N = 0;
    int k = 0;
	scanf("%d", &N);

	int arr[MAX_N] = { 0, };

	for (int i = 0;i < N;i++) {
		int x = 0;
		scanf("%d", &x);
		arr[x]++;
        if(k<x)    k=x;
	}
	for (int i = 0;i < k+1;i++) {
        while(arr[i]--!=0)
            printf("%d\n",i);
	}
}
