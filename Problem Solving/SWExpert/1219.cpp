// 1221, 1219, 11315
#include <iostream>
 
using namespace std;
 
#define MAX_LEN 100
 
int r1[MAX_LEN] = { 0, }; // 첫번째 길
int r2[MAX_LEN] = { 0, }; // 두번째 길
 
// 재귀
int go(int now) {
    //cout << "now : " << now << endl;
    if (now == 99) return 1;
 
    if (r1[now])  // 다음 길로 갔는데 도착해서 ret값이 1이면 1 리턴
        if(go(r1[now])) return 1;
     
    if(r2[now]) 
        if(go(r2[now])) return 1;
     
    return 0;
}
 
int main() {
     
    int T = 10; //tc 개수
 
    for (int t = 1; t <= T; t++) {
        fill_n(r1, MAX_LEN, 0);
        fill_n(r2, MAX_LEN, 0);
 
        cin >> t;
        int N = 0;
        cin >> N;
 
        // 입력
        for (int i = 0; i < N; i++) {
            int start, end;
            cin >> start >> end;
            if (r1[start] == 0) r1[start] = end; // 아직 첫번재 길이 입력안됐을 때
            else r2[start] = end;
        }
 
        int ans = 0;
        // 무조건 0에서 출발
        ans = go(0);
 
        printf("#%d %d\n", t, ans);
    }
    return 0;
}
