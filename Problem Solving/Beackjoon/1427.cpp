#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string N;
	cin >> N;
	int len = N.length();
	int* arr = new int[len];
	for (int i = 0;i < len;i++) {
		arr[i] = N[i] - '0';	// char to int
	}
	sort(arr, arr + len);

	for (int i = len-1;i >=0;i--) {
		cout << arr[i];
	}
	cout << "\n";

}
