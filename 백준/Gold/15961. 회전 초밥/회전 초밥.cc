// BOJ 15961 회전초밥
// 투포인터, 슬라이딩 윈도우
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 3000010;
const int MAXd = 3010;
int arr[MAXN] = { 0, }; // 벨트 위에 있는 초밥 번호
int check[MAXd] = { 0, }; // 초밥 종류 (1~d) 개수 체크

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, d = 0, k = 0, c = 0;
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int start = 0, end = k;
	check[c] = 1;
	for (int i = start; i < end; i++) {
		check[arr[i]]++;
	}
	int types = 0, maxt=0;
	for (int i = 1; i <= d;i++) {
		if (check[i]) types++;
	}

	// sliding window
	for (start = 1; start < N; start++) {
		end = (start + k-1);
		end = end >= N ? end % N : end; // 회전

		// 이번 k개에서 초밥 가짓수는
		check[arr[start - 1]]--;
		if (check[arr[start - 1]] == 0) types--;
		check[arr[end]]++;
		if (check[arr[end]] == 1) types++;
		
		if (maxt <= types) {
			maxt = types; 
		}
	}

	cout << maxt << "\n";

	return 0;
}