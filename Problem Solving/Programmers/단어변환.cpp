// Programmers 코딩테스트 연습 - 단어변환
// BFS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<string, int> psi;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<psi> que;
    bool visited[100] = { false, };

    que.push_back(make_pair(begin, 0));

    while (!que.empty()) {
        psi cur = que.front(); que.erase(que.begin()); // pop()

        if (cur.first == target) {
            answer = cur.second;
            break;
        }

        // cur.first와 한 글자만 차이나는 word que에 push
        for (int j = 0; j < words.size(); j++) {
            string w = words[j];
            if (visited[j]) continue;

            int dif = 0;
            for (int i = 0; i < w.length(); i++) {
                if (cur.first[i] != w[i]) dif++;
            }
            if (dif == 1) {
                visited[j] = true; // 방문 체크
                que.push_back(make_pair(w, cur.second + 1));
            }
        }
    }

    return answer;
}
int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log"};

    int ans = solution(begin, target, words);
    cout << ans << endl;
}