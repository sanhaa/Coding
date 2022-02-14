// S_1256 K 번째 접미어
#include <iostream>
using namespace std;

const int LEN = 401;

bool is_min(char* min, char * s) {
	int idx = 0;
	while (min[idx] || s[idx]) {
		if (min[idx] > s[idx]) {
			return false;
		}
		else if (min[idx] < s[idx]) return true;
		idx++;
	}
}


int main() {
	freopen("input.txt", "r", stdin);

	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		char str[LEN] = { 0, };
		char A[LEN][LEN] = { 0, };
		int K = 0;
		cin >> K;
		scanf("%s", str);
		
		int len = 0;
		while (str[len]) len++;

		// 접미어 만들기
		for (int i = 0; i < len; i++) {
			int k = 0;
			for (int j = i; j < len; j++,k++) {
				A[i][k] = str[j];
			}
		}

		int min = 0;
		for (int i = 0; i < len-1; i++) {
			min = i;
			for (int j = i + 1; j < len; j++) {
				if (!is_min(A[min], A[j])) { // 최솟값 업데이트가 필요하다면
					min = j;
				}
			}
			swap(A[i], A[min]);
		}

		//for (int i = 0; i < len; i++) printf("%s ", A[i]);
		//cout << endl;

		printf("#%d %s\n", t, A[K-1]);
	}


	return 0;
}
