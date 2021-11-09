// BOJ 1164 카드 2
// 홀수 버리고, 짝수는 맨 밑으로
// queue 이용

#include <iostream>
using namespace std;

const int MAX_LEN = 1000000;

int main(){
    int N = 0; cin>>N;
    int que[MAX_LEN] = {0,}; 

    int front = 0, rear = -1;

    for(int n = 1; n <=N;n++){
        que[++rear] = n;
    }

    int cnt = 1;
    while(rear - front >= 1){
        if(cnt % 2 != 0){ // 홀수 pop
            que[front] = 0; front++;
        }
        else {// push and pop
            que[++rear] = que[front];
            que[front] = 0; front++;
        }
        cnt++;
    }

    cout<<que[front]<<endl;

    return 0;
}