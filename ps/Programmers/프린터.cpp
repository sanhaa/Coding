// 프로그래머스 > 코딩테스트연습 > 스택/큐 > 프린터
// algorithm 헤더파일 = max_element
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> q;
    // init q
    for (int i = 0; i < priorities.size(); i++) q.push_back(i);
    
    int cnt = 0; // 프린트 개수

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
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    
    cout<<solution(priorities, 0)<<endl;

	return 0;
}
