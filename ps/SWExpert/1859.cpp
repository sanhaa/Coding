#include <iostream>
#include <vector>
 
using namespace std;
 
int price[1000000] = { 0, };
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
 
int main() {
 
    //freopen("input.txt", "r", stdin);
 
    int T = 0;
    cin >> T; // tc 개수
 
    for (int t = 0; t < T; t++) {
        //vector<int> price;
 
        long long int output = 0;
        int N = 0;
        cin >> N;
 
        // input
        for (int n = 0; n < N; n++) {
            cin >> price[n];
        }
 
        int mx = 0, mi = 0;
        for (int i = 0; i < N; i++) {
            if (mi <= i) { // 현재 날짜 이후 가격에 팔아야 하기 때문에
                mx = 0; // 최대 가격 새로 구하기
                // i+1부터 끝까지 중에 제일 큰 값 구하기
                for (int j = i + 1; j < N; j++) {
                    if (mx < price[j]) {
                        mx = price[j];
                        mi = j;
                    }
                }
            }
            // 구한 제일 큰 값이 현재 가격보다 크면 팔기
            if (mx > price[i]) {
                output += mx - price[i];
            }
        }
 
        // output
        printf("#%d %lld\n", t + 1, output);
    }
 
}
