#include <iostream>
#include <queue>
 
using namespace std;
 
const int SIZE = 101;
const char sharp = '#';
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
int main() {
 
    int t = 0;
    while (++t <= 10) {
        int n, start;
        cin >> n >> start;
 
        bool arr[SIZE][SIZE] = { 0, };
        int from, to;
        for (int i = 0; i < n/2; i++) {
            cin >> from >> to;
            arr[from][to] = 1;
        }
 
        int max_level = 0;
        int max_node = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, start));
 
        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
             
            if (max_level < now.first) {
                max_level = now.first;
                max_node = now.second;
            }
            else if (max_level = now.first) {
                max_node = max(max_node, now.second);
            }
 
            // now는 이미 연락되었기 때문에 now 로 도착하는 간선 다 필요없다
            for (int i = 1; i < SIZE; i++) {
                arr[i][now.second] = 0;
            }
 
            // now기준 연결된 노드 큐에 넣기
            for (int i = 1; i < SIZE; i++) {
                if (arr[now.second][i] == 1) {
                    q.push(make_pair(now.first + 1, i));
                    arr[now.second][i] = 0;
                }
            }
        }
 
        cout << sharp<<t<<" " << max_node << endl;
    }
}
