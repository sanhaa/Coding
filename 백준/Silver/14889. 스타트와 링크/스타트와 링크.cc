#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int arr_len = 20; // # define 이랑 차이?
int S[arr_len][arr_len] = { 0, }; // 능력치 input 받을 배열

vector<int> start, link; // 각각 두 팀에 어떤 인덱스가 들어가나

int start_sum, link_sum;

pair<int, int> in_start, in_link;

int min_val = INT_MAX;
int N = 0, teams = 0; // team 수는 half N

struct team {
	int S_sum = 0; // 팀에 뽑힌 사람들의 능력치 합
	vector<int> selected; // 팀에 뽑힌 사람의 인덱스
};


// 함수
int sOfpair(pair<int, int> p);
void go(int idx);

int sOfpair(pair<int, int> p) {
	// 능력치 배열 S에서 i, j에 해당하는 능력치 두개 더하기
	return S[p.first][p.second] + S[p.second][p.first];
}


void go(int idx) {

	if (idx > N ) {

		// start, link팀 각각의 크기가 n/2로 딱 절반일때
		if (start.size() == teams && link.size() == teams) {

			// 변수 초기화
			start_sum = 0;
			link_sum = 0;

			// 2중 for문으로 돌면서 각 팀의 선수를 고릅니다. O(n^2)
			for (int i = 0; i < teams; i++) {
				for (int j = i + 1; j < teams; j++) {
					if (i == j)continue;

					// 1) 스타트팀 2명 골라서
					in_start.first = start[i];
					in_start.second = start[j];

					// 스타트팀 능력치 계산
					start_sum += sOfpair(in_start);

					// 2) 링크팀 2명 골라서
					in_link.first = link[i];
					in_link.second = link[j];

					// 링크팀 능력치 계산
					link_sum += sOfpair(in_link);
				}
			}

			// 최솟값 업데이트 - if문 쓰지 않고 min() 쓰는게 더 빠를까요
			min_val = min(min_val, abs(start_sum - link_sum));

		}
		return;
	}

	// idx선수에 대해 두가지 케이스가 존재한다.
	// 1) 스타트 팀에 넣는다.
	start.push_back(idx);
	go(idx + 1);
	start.pop_back();

	// 2) 링크 팀에 넣는다.
	link.push_back(idx);
	go(idx + 1);
	link.pop_back();
}

int main() {
	// input
	cin >> N;
	teams = N / 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	go(1);

	cout << min_val << endl;
}