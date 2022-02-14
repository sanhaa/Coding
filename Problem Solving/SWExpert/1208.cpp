#include <iostream>
 
using namespace std;
 
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
 
int main() {
 
    for (int t = 0; t < 10; t++) {
        int h[100] = { 0, }; // 100개의 height 저장
        int ans = 0;
        int d = 0; // dump 횟수
        cin >> d;
 
        for (int i = 0; i < 100; i++) {
            cin >> h[i];
        }
        int highest = 0, hi = 0;
        int lowest = 1001, li = 0;
 
        while (d--) {
            highest = 0, hi = 0;
            lowest = 1001, li=0;
            for (int i = 0; i < 100; i++) {
                if (highest < h[i]) {
                    highest = h[i];
                    hi = i;
                }
                if (lowest > h[i]) {
                    lowest = h[i];
                    li = i;
                }
            }
            if (highest == lowest) break;
            //cout << highest << " " << lowest << endl;
            h[hi]--;
            h[li]++;
        }
        highest = 0, lowest = 1001;
        for (int i = 0; i < 100; i++) {
            highest = max(highest, h[i]);
            lowest = min(lowest, h[i]);
        }
 
        ans = highest - lowest;
        printf("#%d %d\n", t + 1, ans);
    }
 
}
