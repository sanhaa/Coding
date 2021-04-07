// J 1141
#include <iostream>
using namespace std;

const int SIZE = 80001;

int main() {
	int top = 0;
	int cows[SIZE] = { 0, };

	int N = 0;
	long long int ans = 0; // c1 + ... cn
	cin >> N; 
	
	for (int i = 0; i < N; i++) {
		int hi = 0; // 소의 키
		cin >> hi;
		while (top > 0 && hi >= cows[top])  {
			cows[top--] = 0; // pop
		}
		ans += top;
		cows[++top] = hi; // push
	}

	cout << ans << endl;
	
}
