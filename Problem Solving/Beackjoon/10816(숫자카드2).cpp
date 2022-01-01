// BOJ 10816 숫자 카드 2
#include <iostream>

using namespace std;

const int SET_IDX = 10000000;
const int MAX_SIZE = 20000010;
int count[MAX_SIZE] = {0,}; // -->  동적할당?

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0; cin>>N;
	for(int i =0;i<N;i++){
		int num = 0; cin>>num;
		count[num + SET_IDX]++;
	}

	cin>>M;
	for(int i = 0; i<M; i++){
		int target = 0; cin>>target;
		cout<<count[target + SET_IDX]<<" ";
	}
	cout<<"\n";
	return 0;
}
