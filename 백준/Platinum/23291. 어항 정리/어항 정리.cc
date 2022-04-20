// BOJ 23291 어항정리
// 구현, 시뮬
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int dr[] = { -1, 1, 0,0 };
int dc[] = { 0,0,-1,1 };

void print_fb(vector<vector<int>> fb) {
	cout << "-------------- printed" << endl;
	for (auto f : fb) {
		for (auto fish : f) {
			cout << fish << " ";
		}
		cout << endl;
	}
	cout << "-------------\n";
}

vector<vector<int>> fish_cnt_control(vector<vector<int>> fb) {
	// copy
	vector<vector<int>> new_fb; 
	new_fb.assign(fb.size(), vector<int>(fb.size()));
	copy(fb.begin(), fb.end(), new_fb.begin());

	vector<vector<int>> check; // 체크 표시용
	check.assign(fb.size(), vector<int>(0));
	for (int i = 0; i < fb.size(); i++) {
		check[i].assign(fb[i].size(), 0);
	}

	int ilen = fb.size();
	for (int i = 0; i < ilen; i++) {
		int jlen = fb[i].size();

		for (int j = 0; j < jlen; j++) {
			if (check[i][j]) continue;
			check[i][j] = 1;

			for (int k = 0; k < 4; k++) {
				// 상하좌우 인접 어항과 물고기 수 비교하기
				int ni = i + dr[k], nj = j + dc[k];
				if (ni < 0 || nj < 0 || ni >= ilen || nj >= fb[ni].size()) continue;
				if (check[ni][nj]) continue;
				//check[ni][nj] = 1; // visit

				int d = (fb[i][j] - fb[ni][nj]); // 개체수차이
				if (d < 0) d *= -1;
				d /= 5;
				if (d <= 0) continue;

				if (fb[i][j] > fb[ni][nj]) {
					new_fb[i][j] -= d;
					new_fb[ni][nj] += d;
				}
				else {
					new_fb[i][j] += d;
					new_fb[ni][nj] -= d;
				}
			}
		}
	}

	return new_fb;
}

vector<vector<int>> to_1line(vector<vector<int>> fb) {
	vector<vector<int>> new_fb(N);
	int len = 0;
	for (int i = 0; i < fb.size(); i++) {
		for (int j = 0; j < fb[i].size(); j++) {
			new_fb[len++].push_back(fb[i][j]);
		}
	}
	return new_fb;
}

void cycle(vector<vector<int>> &fb) {
	// 1. 제일 적은 어항에 +1마리
	int minv = 987654321;
	for (int i = 0; i < fb.size(); i++) {
		if (minv > fb[i][0]) minv = fb[i][0];
	}
	for (int i = 0; i < fb.size(); i++) {
		if (minv == fb[i][0]) fb[i][0] += 1;
	}
	//print_fb(fb);

	// 2. left most 어항 쌓기
	fb[1].push_back(fb[0][0]);
	fb.erase(fb.begin());
	//print_fb(fb);

	// 3-4. 높이 2이상 90도 회전 쌓기 반복
	int target_cnt = 1; // 공중부양 할 어항 라인 개수
	int h = 2; // 공중부양 할 어항 높이
	while (true) {
		if (h > fb.size() - target_cnt) break;
		for (int layer = 0; layer < h; layer++) {
			for (int hori = target_cnt - 1; hori >= 0; hori--) {
				fb[target_cnt + layer].push_back(fb[hori][layer]);
			}
		}

		// 쌓아 올린 어항 지우기
		for (int i = 0; i < target_cnt; i++) {
			fb.erase(fb.begin());
		}

		//cout << "3. 90 rotation result -- "<<target_cnt<<" "<<h<<endl;
		//print_fb(fb);

		int next_h = target_cnt + 1; // 90도 회전해서 다음 h = 가로 cnt + 1층 쌓기
		target_cnt = h; // 90도 회전하면서 다음 차례에는 이번 높이만큼 target이 됨
		h = next_h;
	}

	// 5. 물고기 수 조절
	fb = fish_cnt_control(fb);
	//cout << "fish_cnt_control result ----" << endl;
	//print_fb(fb);

	// 일렬 배열
	fb = to_1line(fb);
	//cout << "to_1line" << endl;
	//print_fb(fb);

	// 6. 절반, 180도 회전
	target_cnt = N / 2;
	for (int i = target_cnt; i < N; i++) {
		fb[i].push_back(fb[N - 1 - i][0]); 
	}
	// pop
	for (int i = 0; i < target_cnt; i++) fb.erase(fb.begin());

	target_cnt = N / 4;
	//cout << "fb size is N/2 now : " << fb.size() << endl;

	for (int hori = target_cnt; hori < fb.size(); hori++) {
		for (int layer = 1; layer >= 0; layer--) {
			fb[hori].push_back(fb[fb.size() - 1 - hori][layer]);
		}
	}
	// pop
	for (int i = 0; i < target_cnt; i++) fb.erase(fb.begin());

	//cout << "after half 180 rotation: " << endl;
	//print_fb(fb);

	fb = fish_cnt_control(fb);
	fb = to_1line(fb);

	//cout << "after 1 cycle : \n";
	//print_fb(fb);
}

int main() {
	int K = 0; cin >> N >> K;
	vector<vector<int>> fb; // fish bowl
	for (int i = 0; i < N; i++) {
		fb.push_back(vector<int>(0, 0));

		int f = 0; cin >> f;
		fb[i].push_back(f);
	}

	int answer = 0; // 어항정리 사이클 횟수
	while (true) {
		answer++;
		cycle(fb);

		int maxv = 0, minv = 987654321;
		for (int i = 0; i < fb.size(); i++) {
			for(int j = 0; j < fb[i].size(); j++) {
				if (maxv < fb[i][j]) maxv = fb[i][j];
				if (minv > fb[i][j]) minv = fb[i][j];
			}
		}
		if (maxv - minv <= K) break;
	}

	cout << answer << endl;

	return 0;
}