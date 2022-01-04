// BOJ 10250 ACM 호텔  
// (N % H)(N / H + 1) = (앞 두자리) (뒷 두자리)
// ex. 30 50 72 -> 1203
#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T = 0; cin>>T;
	for(int i = 0; i<T;i++){
		int H = 0, W = 0, N = 0;
		cin>>H>>W>>N;
		
		int num1 = N%H; // floor
		int num2 = N / H + 1; // room number

		if(num1==0) { // 나누어 떨어질 때 예외 처리 
			num1 = H;
			num2 -= 1;
		} 
		cout<<num1;
		
		if(num2<10) cout<<"0";
		cout<<num2<<"\n";
	}

	return 0;
}
