// BOJ 3687 성냥개비
// DP
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 110;
int n = 0;
// req[i] = 숫자 i를 만들기 위해 필요한 성냥개비 개수
int req[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; 
/// <summary>
/// 수의 길이가 최대 50까지라 int 범위를 벗어남
/// </summary>
string minDP[MAXN] = { "",}; // minDP[i] = i개의 성냥개비로 만들 수 있는 가장 작은 수
string maxDP[MAXN] = { "",};

bool compare(string a, string b) {
	if (a.length() < b.length()) return true;
	else if (a.length() == b.length()) {
		int i = 0;
		while (a[i] == b[i]) {
			if (i + 1>= a.length()) {
				return true;
			}
			i++;
		}
		return a[i] < b[i];
	}
	return false;
}

int main() {
	cin.tie(NULL); 
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	// DP 배열 초기화
	minDP[1] = string(50, '1'); // MAX
	minDP[2] = "1"; minDP[3] = "7"; minDP[4] = "4"; minDP[6] = "6";
	maxDP[2] = "1"; maxDP[3] = "7"; maxDP[4] = "11"; 

	int TC = 0; cin >> TC;
	while (TC--) {
		n = 0; cin >> n;

		if (minDP[n] != "" && maxDP[n] != "") {
			cout << minDP[n] << " " << maxDP[n] << "\n";
			continue;
		}

		// DP[n] 구하기
		for (int i = 2; i <= n; i++) {
			string minv=minDP[i], maxv=maxDP[i];

			for (int num = 0; num <= 9; num++) {
				if (i - req[num] < 0) continue;
				string temp1 = minDP[i - req[num]] + char(num + '0');
				string temp2 = char(num + '0') + maxDP[i - req[num]];
				// minv, maxv update
				/* string으로 된 수의 크기 판단
					1. minv, maxv가 비어있으면 무조건 업데이트
					2. 길이가 길면 무조건 크다.
					3. 길이가 같을 때는 string 부등호로 비교결과 = 정수 비교 결과
				*/
				if (temp1[0] != '0') {
					if (minv == "") minv = temp1;
					else if (!compare(minv, temp1)) minv = temp1;
				}
				if (temp2[0] != '0') {
					if (maxv == "")maxv = temp2;
					else if (compare(maxv, temp2)) maxv = temp2;
				}

			}
			minDP[i] = minv;
			maxDP[i] = maxv;
		}
		cout << minDP[n] << " " << maxDP[n] << "\n";
	}	

	return 0;
}