#include <iostream>

using namespace std;

int main() {

	int T = 0; // 테스트 케이스 개수
	int num = 0;
	cin >> T;
	for(int i=0;i<T;i++) {  // 테스트 케이스 개수만큼 정수를 입력받고 답을 출력하는 것을 반복.
		cin >> num;
       
		int* DP = new int[num+1]();
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;

		for (int j = 4;j < num+1;j++) {
			DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
		}
		cout << DP[num] << endl;
	}
}
