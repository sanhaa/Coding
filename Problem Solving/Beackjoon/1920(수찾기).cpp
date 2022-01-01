// BOJ 1920 수 찾기
// Quick sort 구현 잘하기 어려워서 라이브러리 썼음
// endl, cin.tie(), sync() 안 하면 시간초과남

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;
int A[MAX_N] = {0,};

bool binary_search(int target, int low, int high){
	int mid=(low+high)/2;
	if(high-low<=1) {
		if(target == A[low] || target == A[high]) return 1;
		else return 0;
	}

	if(target < A[mid]){
		return binary_search(target, low, mid);
	}
	else if (target > A[mid]){
		return binary_search(target, mid, high);
	}
	else
		return 1;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0; cin>>N;
	for(int i = 0; i<N;i++){
		cin>>A[i];
	}
	sort(A, A+N);

	int M = 0; cin>>M;
	for(int i = 0; i<M;i++){
		int target = 0; cin>>target;
		cout<<binary_search(target, 0, N-1)<<"\n";
	}

	return 0;
}
