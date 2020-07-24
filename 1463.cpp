#include <iostream>
#include <algorithm>

using namespace std;


int* m;

int DP(int n) {
	if (n == 1)	return m[1]=0;
	else if (n == 2)	return m[2]=1;
	else if (n == 3) return m[3]=1;

	else if (m[n] == 0) {
		if (n % 3 == 0 && n%2==0) {
			m[n] = 1 + min(DP(n/3), DP(n/2));
		}
		else if (n % 2 == 0) {
			m[n] = 1 + min(DP(n / 2), DP(n-1));
		}
		else if (n % 3 == 0) {
			m[n] = 1 + min(DP(n / 3), DP(n-1));
		}
		else {
			m[n] = 1 + DP(n - 1);
		}
		return m[n];
	}
	else {
		return m[n];
	}
}

int main() {
	int num = 0;
	cin >> num;

	m = new int[num+1]();
	cout<<DP(num)<<endl;
}
