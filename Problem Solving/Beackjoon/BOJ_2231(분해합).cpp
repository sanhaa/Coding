// BOJ 2231 분해합
#include <iostream>

using namespace std;

int _sum(int N){
	int ret = N;
	int temp = N;
	while(temp){
		ret += (temp % 10); // add each digit num
		temp /= 10;
	}
	return ret;
}

int main(){
	int N = 0; // input
	cin>>N;
	int ans = 0;
	for(int n=1;n<N;n++) {
		int decom_sum = _sum(n);
		if(decom_sum  == N) {
			ans = n;
			break;
		}
	}
	cout<< ans <<endl; // creator not exist
	return 0;
}
