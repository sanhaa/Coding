// 프로그래머스 > 코딩테스트연습 > 스택 / 큐 > 다리를 지나는 트럭

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    vector<pair<int, int>> bridge; // 다리에 올라와 있는 트럭, 올라온 시각 pair
    
    int time = 1;
    bridge.push_back(make_pair(*truck_weights.begin(), time));

    int total_weight = *truck_weights.begin();

    vector<int>::iterator next_iter = truck_weights.begin() + 1;

    while (!bridge.empty()) {
        time++;
        if (time - bridge.front().second >= bridge_length) {
            total_weight -= bridge.front().first;
            bridge.erase(bridge.begin()); // pop()
        }

        // 새 트럭 올리기
        if (next_iter == truck_weights.end()) continue;

        int next_w = *next_iter;
        if (bridge_length > bridge.size() && weight >= total_weight + next_w) {
            bridge.push_back(make_pair(next_w, time)); // push
            total_weight += next_w;
            next_iter++;
        }
    }

    return time;
}

int main() {

    int l = 100;
    int w = 100;
    vector<int> tw = { 10,10,10,10,10,10,10,10,10,10 };

    cout << solution(l, w, tw) << endl;

	return 0;
}



