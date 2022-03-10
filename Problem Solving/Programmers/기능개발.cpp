// 프로그래머스 > 스택/큐 > 기능개발 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    // 기능 작업 완료 날짜 구하기
    vector<int> days;
    for (int i = 0; i < progresses.size(); i++) {
        int temp = 100 - progresses[i];
        days.push_back(temp / speeds[i] + min(temp % speeds[i], 1));
    }
    
    while (!days.empty()) {
        int cur = days.front(); // 이번 배포
        days.erase(days.begin());

        int cnt = 0; // 함께 배포되는 기능 개수
        while (!days.empty() &&  cur >= days.front()) {
            cnt++;
            days.erase(days.begin()); // pop
        }
        answer.push_back(cnt + 1);
    }

    return answer;
}

int main() {

    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

    vector<int> ans = solution(progresses, speeds);
    cout << "ans -- " << endl;
    for (int a : ans) {
        cout << a << endl;
    }

	return 0;
}
