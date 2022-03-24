
 
#include <iostream>
using namespace std;
 
const int MAX_N = 1001;
const int MAX_W = 10001;
 
int w[MAX_N] = { 0, };
int p[MAX_N] = { 0, };
int K[MAX_N][MAX_W] = { 0, };
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
int main() {
    int N, W;
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> p[i];
    }
 
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0 || w[i] > W) K[i][j] = 0;
            else if (w[i] > j) {
                K[i][j] = K[i - 1][j];
            }
            else {  
                K[i][j] = max(K[i - 1][j - w[i]] + p[i], K[i - 1][j]);
                if(w[i] + w[i] <= j) // 같은 무게를 여러번 쓸 수 있다.
                    K[i][j] = max(K[i][j], K[i][j - w[i]] + p[i]);
            }
        }
    }
 
    cout << K[N][W] << endl;
 
}
