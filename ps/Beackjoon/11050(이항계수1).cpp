// BOJ 11050 이항 계수 1
#include <iostream>

using namespace std;

int main(){
	int N = 0, K = 0;
	cin>>N>>K;
	int dividend = 1, divisor = 1;
	for(int i = 0; i<K;i++){
		dividend *= N;
		N--;
	}
	for(int i = 1;i<=K;i++){
		divisor *= i;
	}
	cout<<dividend/divisor<<endl;

	return 0;
}
