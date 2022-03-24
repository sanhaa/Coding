#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE = 13;

int ABS(int a) {
	return a > 0 ? a : -a;
}
// first : y
pair<int, int> pos[] = { {3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int Lx = 0, Ly = 3;
	int Rx = 2, Ry = 3;

	for (int num : numbers) {

		if (pos[num].second == 0) {
			answer += "L";
			Lx = pos[num].second; Ly = pos[num].first;
		}
		else if (pos[num].second == 2) {
			answer += "R";
			Rx = pos[num].second; Ry = pos[num].first;
		}

		else { // 가운데 있는 키패드
			// 거리 비교해서 결정
			//int dist1 = ABS((now_L - 1) / 3 - (num - 1) / 3) + ABS((now_L - 1) % 3 - (num - 1) % 3);
			//int dist2 = ABS((now_R - 1) / 3 - (num - 1) / 3) + ABS((now_R - 1) % 3 - (num - 1) % 3);
			int dist1 = ABS(Lx - pos[num].second) + ABS(Ly - pos[num].first);
			int dist2 = ABS(Rx - pos[num].second) + ABS(Ry - pos[num].first);

			if (dist1 < dist2) {
				answer += "L";
				Lx = pos[num].second; Ly = pos[num].first;
			}
			else if (dist1 > dist2) {
				answer += "R";
				Rx = pos[num].second; Ry = pos[num].first;
			}
			else {
				if (hand == "left") {
					answer += "L";
					Lx = pos[num].second; Ly = pos[num].first;
				}
				else {
					answer += "R";
					Rx = pos[num].second; Ry = pos[num].first;
				}
			}
		}
	}

	return answer;
}

int main() {

	vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };

	std::cout << solution(numbers, "left") << endl;

	return 0;
}
