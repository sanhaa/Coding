#include <iostream>
 
using namespace std;
 
const int MAX_LEN = 1000;
 
// 내가 만든 min함수: 둘중에 하나라도 음수면 0을 반환
int min(int a, int b) {
    if (a < 0 || b < 0) return 0;
    else
        return a < b ? a : b;
}
 
 
int main() {
    int T = 10;
    for (int t = 0; t < T; t++) {
        int ans = 0; // 정답, 조망권이 확보된 세대 수
        int buildings[MAX_LEN] = { 0, }; // 최대 1000개의 건물의 높이 앞2, 뒤2는 0
 
        int len = 0; // 가로길이 = 건물 수 + 4
 
        /* input */
        cin >> len;
        for (int j = 0; j < len; j++) {
            cin >> buildings[j];
        }
 
        // 계산
        for (int i = 2; i < len-2; i++) {
            if (buildings[i] == 0) continue;
            int h = buildings[i]; // 현재 빌딩 높이
 
            // 각각 왼쪽, 오른쪽 기준으로 조망권 확보한 세대 수
            int left = min(h-buildings[i - 1], h-buildings[i - 2]);
            int right = min(h-buildings[i + 1], h-buildings[i + 2]);
 
            ans += min(left, right); // 이번 building에서 조망권 확보 세대수를 더함
        }
         
 
        // output
        printf("#%d %d\n", t + 1, ans);
    }
}
