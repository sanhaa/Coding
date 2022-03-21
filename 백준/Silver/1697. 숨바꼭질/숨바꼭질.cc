// BOJ 1697 숨바꼭질
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000; 
//pair<int, int> q[MAXN*10];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N = 0, K = 0;
    cin >> N >> K;
    //int front=-1, back = -1;
    vector<pair<int, int> > q;
    bool visit[MAXN+10] = { false, };

    //q[++back] = make_pair(N, 0); // push
    q.push_back(make_pair(N, 0));
    visit[N] = true;

    while (!q.empty()) {
        //pair<int, int> cur = q[++front]; // pop
        pair<int, int> cur = q.front(); q.erase(q.begin());

        if (cur.first == K) {
            cout << cur.second << "\n";
            break;
        }
        if (cur.first + 1 <= MAXN && cur.first < K && !visit[cur.first + 1]) {
            visit[cur.first + 1] = true;
            q.push_back(make_pair(cur.first + 1, cur.second + 1));
        }
        if (cur.first - 1 >= 0 && !visit[cur.first - 1]) {
            visit[cur.first - 1] = true;
            q.push_back(make_pair(cur.first - 1, cur.second + 1));
        }
        if (cur.first<<1 <= MAXN && !visit[cur.first << 1]) {
            visit[cur.first * 2] = true;
            q.push_back(make_pair(cur.first<<1, cur.second + 1));
        }
    }

    return 0;
}