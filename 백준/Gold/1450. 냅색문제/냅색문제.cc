#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

const int MAXN = 40;

ll N = 0, C = 0;

void print_arr(vector<ll> v) {
	for (auto iter = v.begin(); iter != v.end(); iter++) cout << (*iter) << " ";
	cout << endl;
}

void cal_sum(vector<ll>& v, vector<ll> arr, ll idx, ll sum) {
	if (idx >= arr.size() || sum + arr[idx] > C) return;

	v.push_back(sum + arr[idx]);

	cal_sum(v, arr, idx + 1, sum);
	cal_sum(v, arr, idx + 1, sum + arr[idx]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	ll answer = 0;

	ll in_arr[MAXN] = { 0, };
	for (int i = 0; i < N; i++) cin >> in_arr[i];

	sort(in_arr, in_arr + N);

	// 두 배열로 나누기
	vector<ll> a1, a2;
	ll half = N >> 1;
	for (int i = 0; i < N; i++) {
		if (i < half) a1.push_back(in_arr[i]);
		else a2.push_back(in_arr[i]);
	}


	// 각 배열의 합배열 구하기
	vector<ll> v1, v2;

	v1.push_back(0); v2.push_back(0);
	cal_sum(v1, a1, 0, 0);
	sort(v1.begin(), v1.end());
	//print_arr(v1);

	cal_sum(v2, a2, 0, 0);
	sort(v2.begin(), v2.end());
	//print_arr(v2);

	// 합이 C이하인 경우의 수 찾기
	for (int i = 0; i < v1.size();i++) {

		// 이분탐색으로 target 찾기 귀찮으니까 선형탐색
		//ll find = 0;
		//for (int j = 0; j < v2.size(); j++) {
		//	if (v1[i] + v2[j] > C) break;
		//	find = j;
		//}
		////answer += (find >= v2.size()) ? find : (find+1); 
		//answer += (find + 1); // 찾은 인덱스 포함
		
		answer += upper_bound(v2.begin(), v2.end(), C - v1[i]) - v2.begin();
	}

	cout << answer << "\n";

	return 0;
}