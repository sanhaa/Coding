// BOJ 15829 Hashing
// 주어진 해시함수로 해시값 구하기
// r = 31, M = 1234567891
// H = (a0*r^0 + a1*r^1 + a2*r^2 + ...) % M
#include <iostream>

using namespace std;

const int LEN = 60;

int main(){
    int L = 0, r = 31, M = 1234567891;
    char str[LEN] = "";
    cin>>L>>str;
    
    long long int H = 0; // hash value, 
    long long int r_pow = 1; // r 제곱수
    for (char c:str){
        if(c=='\0') break;
        H += ((c-'a' + 1)*(r_pow))%M; // a = 1
        r_pow *= r; r_pow%=M;
    }
    cout<<H%M<<"\n";

    return 0;
} 