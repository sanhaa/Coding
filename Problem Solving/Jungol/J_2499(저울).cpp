#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int weights[1010] = { 0, }; // 추

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> weights[i];
	//, greater<int>()
	sort(weights, weights + N); 

	int num = 0;
	for (int i = 0; i < N; i++) {
		if (num + 1 < weights[i]) break;
		num += weights[i];
	}
	cout << num+1 << endl;

	return 0;
}
