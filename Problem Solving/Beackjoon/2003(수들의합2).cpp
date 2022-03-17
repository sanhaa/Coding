#include <iostream>

using namespace std;

const int MAXN = 10010;

int main(){
    int N = 0, M = 0, ans = 0;
    cin >> N >> M;
    int A[MAXN] = {0,};

    for(int x = 0; x<N;x++){
        cin>>A[x];
    }
    int start=0, end = 0, sum = 0;
    for(start;start<N;start++){
        while(sum < M && end < N){
            sum += A[end];
            end++;
        }
        if(sum == M) ans++;
        sum -= A[start];
    }

    cout<<ans<<endl;
    return 0;
}