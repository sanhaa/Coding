/// BOJ 2775 부녀회장이 될테야
// k층의 n호에는 몇 명이 살고 있는지 <= 14
// a층의 b호 people = sum ((a-1)층  1호 ~ b호 people)
// 아파트: 0층 ~ , 1호 ~ 
// 0층 i호 = i명
////////////////////////////////
// 0층 1, 2, 3, 4, 5
// 1층 1, 3, 6, 10, 15
// 2층 1, 4, 10, 20, 35
#include <iostream>

using namespace std;

const int MAXN = 15;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // memoization
    int people[MAXN][MAXN] = {1,};
    for(int b=1;b<MAXN;b++) people[0][b] = b; // 0층 초기화

    for(int a = 1; a<MAXN; a++){ // a층
        for(int b = 1; b<MAXN; b++){ // b호
            people[a][b] = people[a][b-1] + people[a-1][b];
        }
    }

    // Test case T
    int T = 0; cin>>T;
    while(T--){
        int k = 0, n = 0;
        cin>>k>>n;
        cout<<people[k][n]<<"\n";
    }

    return 0;
}