// BOJ 1966 프린터큐
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<int> q;
    // init q
    for (int i = 0; i < priorities.size(); i++) q.push_back(i);

    int cnt = 0; // 프린트된 문서 개수

    while (!q.empty()) {
        int cur = q.front();

        q.erase(q.begin());
        bool printed = true;

        for (int p : q) {
            if (priorities[cur] < priorities[p]) {
                q.push_back(cur);
                printed = 0;
                break;
            }
        }

        if (printed) {
            cnt++;
            if (cur == location) {
                answer = cnt; break;
            }
        }
    }

    return answer;
}

int main() {
    int TC = 0; cin >> TC;

    while (TC--) {
        int N = 0, M = 0; cin >> N >> M;
        vector<int> priorities;
        for (int i = 0; i < N; i++) {
            int a = 0; cin >> a;
            priorities.push_back(a);
        }
        cout << solution(priorities, M) << "\n";
    }

    return 0;
}