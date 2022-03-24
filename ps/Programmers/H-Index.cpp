// Programmers > 코딩테스트연습 > 정렬 > H-Index
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 내림차순
bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);

    for (int idx = 0; idx < citations.size(); idx++) {
        if (idx + 1 <= citations[idx]) {
            answer = idx + 1;
        }
        else break;
    }
    
    return answer;
}

int main() {
    vector<int> citations = {9, 7, 6, 2, 1};

    cout<<solution(citations)<<endl;

    return 0;
}
