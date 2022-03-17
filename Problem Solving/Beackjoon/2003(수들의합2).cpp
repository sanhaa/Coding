#include <iostream>

using namespace std;

const int MAXN = 10010;

int main(){
    int N = 0, M = 0, ans = 0;
    cin >> N >> M;
    int A[MAXN] = {0,}, SUM[MAXN] = {0,};

    for(int x = 0; x<N;x++){
        cin>>A[x+1];
        SUM[x+1] = SUM[x] + A[x+1];
    }
    
    for(int i = 1;i<=N;i++){
        for(int j = i;j<=N;j++){
            // sum A[i] ~ A[j]
            if(SUM[j] - SUM[i-1] == M) ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}