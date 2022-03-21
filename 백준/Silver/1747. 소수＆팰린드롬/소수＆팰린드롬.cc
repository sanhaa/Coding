// BOJ 1747 소수&팰린드롬

#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N = 0; cin>>N; // <= 100만
    int M = N;
    while(true){
        int temp = M;
        bool is_palin = true, is_prime = true;
        
        // 1. 팰린드롬 판단
        char str[7];
        int idx = 0;
        while(temp>0){ // 역순으로 저장됨
            str[idx++] = (temp%10) + '0';
            temp/=10;
        }
        for(int i = 0; i<idx/2;i++){
            if(str[i] != str[idx-1-i]) is_palin = false;
        }
        
        if(is_palin) {
            // 2. 소수 판단
            int div = 2;
            while(M > div){
                if(M%div==0) {
                    is_prime = false;
                    break;
                }
                div++;
            }
            if(M!=1 && is_prime)  // 소수
                break;   
        }
        M++;
    }
    cout<<M<<endl;
    return 0;
}
