// BOJ 11866 요세푸스 문제0
#include <iostream>

using namespace std;

int main(){
    int N = 0, K = 0;
    cin>> N >> K;

    int cnt = 0, n = 0;
    bool check[2000] = {0,};
    int res[2000] {0,};

    while(cnt < N){
        int k = 0;
        while(k<K){
            n++;         if(n > N) n%=N;
            if(!check[n]) {
                k++;
            } 
        }
        res[cnt++] = n;
        check[n] = true;    
    }

    cout<<"<";
    for(int i = 0; i<N-1;i++){
        cout<<res[i]<<", ";
    }
    cout<<res[N-1]<<">"<<endl;

    return 0;
}