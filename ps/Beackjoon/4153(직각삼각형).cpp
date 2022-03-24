// BOJ 4153 직각삼각형
#include <iostream>

using namespace std;

int main(){
	int A=0, B=0, C=0;
	while(1){
		cin>>A>>B>>C;
		if(A==0) break;
		int A2 = A*A, B2 = B*B, C2 = C*C;
		if(A2 + B2 == C2 || A2 + C2 == B2 || B2 + C2 == A2){
			cout<<"right\n";
		}
		else{
			cout<<"wrong\n";
		}
	}

	return 0;
}
