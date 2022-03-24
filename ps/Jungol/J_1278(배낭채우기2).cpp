
// J 1278
// knapsack - DP, DFS, BFS(+PQ)
// 보석 개수 무개당 한개씩
#include <iostream>
using namespace std;
 
const int MAX_N = 1001;
const int MAX_W = 10001;
// K[i][j] = 보석 i개 사용해서 j 보다 넘지 않는 무게 중 최대 가치
int K[MAX_N][MAX_W] = { 0, };
 
int max_p(int p1, int p2) {
    return p1 > p2 ? p1 : p2;
}
 
int main() {
    int N = 0, W = 0;
    cin >> N >> W;
    int w[MAX_N] = { 0, };
    int p[MAX_N] = { 0, };
 
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> p[i];
    }
 
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (i == 0 || w[i] > W) K[i][j] = 0;
            else if(w[i] >  j) K[i][j] = K[i - 1][j];
            else{
                // 할 수 있는 건 이 i번째 보석을 포함하거나 안하거나
                K[i][j] = max_p(K[i-1][j-w[i]] + p[i], K[i-1][j]);
            }
        }
    }
 
    cout << K[N][W] << endl;
 
    return 0;
}
