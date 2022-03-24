// BOJ 5585 (거스름돈)
#include <iostream>

using namespace std;

int main() {
	int M = 0;
	cin >> M;
	M = 1000 - M; 

	int coins[6] = { 500,100,50,10,5,1 };
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		cnt += M / coins[i];
		M %= coins[i];
	}

	cout << cnt << "\n";
}
