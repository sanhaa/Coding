// BOJ 2292 벌집
#include <iostream>

using namespace std;

int main(){
    int N = 0; cin>>N; // <=10억
    int answer = 1; // 지나는 방의 개수 (시작 포함)

     // 이번 레벨 방의 개수
     // ex. 1 -> 6 (2~7)-> 12 (8~19) -> 18 (20~37) 
    int rooms = 6;
    while(N>1){
        answer+=1;
        N -= rooms;
        rooms += 6;
    }

    cout<<answer<<endl;
    return 0;
}