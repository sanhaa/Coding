// BOJ 2864 5와 6의 차이
// 그리디
// 합의 최소 = 모든 6 ->5
// 합의 최대 = 모든 5 -> 6
#include <iostream>
#include <string>

using namespace std;

int main() {

	int A = 0, B = 0;
	cin >> A >> B;

	string sA= to_string(A), sB = to_string(B);
	int Alen = sA.length(), Blen = sB.length();

	// min sum
	for (int i = 0; i < Alen;i++) 
		if (sA[i] == '6') sA[i] = '5';
	for (int i = 0; i < Blen; i++) 
		if (sB[i] == '6') sB[i] = '5';

	cout << stoi(sA) + stoi(sB) << " ";

	for (int i = 0; i < Alen; i++)
		if (sA[i] == '5') sA[i] = '6';
	for (int i = 0; i < Blen; i++)
		if (sB[i] == '5') sB[i] = '6';

	cout << stoi(sA) + stoi(sB) << "\n";

	return 0;
}