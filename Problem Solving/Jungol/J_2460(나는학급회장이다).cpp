/*
2021-04-22
J 1078
*/
#include <iostream>
using namespace std;

int MAX(int a, int b, int c) {
	if (a > b) {
		if (c > a) {
			return c;
		}
		else if(c < a){
			return a;
		}
		else return -2;
	}
	else if(a < b) { // a < b
		if (b > c) { 
			return b;
		}
		else if( b < c) {
			return c;
		}
		else return -3;
	}
	else {
		if (a < c) {
			return c;
		}
		else return -1;
	}
}

int main() {

	int N = 0; cin >> N;
	// [0] : 점수 총합 [1] : 1을 받은 횟수 [2] : 2를 받은 횟수 ...
	int s1[4] = { 0, }, s2[4] = { 0 }, s3[4] = { 0, }; // 후보 세명의 선호도 점수

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		s1[a]++; s2[b]++; s3[c]++;
		s1[0] += a; s2[0] += b; s3[0] += c;
	}
	
	int max_score = MAX(s1[0], s2[0], s3[0]); // 최고 점수
	int max_num = 0; // 최고 점수를 가진 후보

	if (max_score == s1[0]) {
		max_num = 1;
	}
	else if (max_score == s2[0]) {
		max_num = 2;
	}
	else if(max_score == s3[0]){
		max_num = 3;
	}
	else { // 최고점수 후보가 여러명
		if (max_score == -1) { //  1 == 2
			max_score = s1[0];
			if (s1[3] > s2[3]) 
				max_num = 1;
			
			else if (s1[3] < s2[3]) max_num = 2;
			else { // 3점 횟수가 같을 때
				if (s1[2] > s2[2]) max_num = 1;
				else if (s1[2] < s2[2]) max_num = 2;
				// 2점 횟수도 같을 때 
			}
		}
		else if (max_score == -2) { // 1 == 3
			max_score = s1[0];
			if (s1[3] > s3[3])
				max_num = 1;

			else if (s1[3] < s3[3]) max_num = 2;
			else { // 3점 횟수가 같을 때

				if (s1[2] > s3[2]) max_num = 1;
				else if (s1[2] < s3[2]) max_num = 2;
				// 2점 횟수도 같을 때 
			}
		}
		else if (max_score == -3) { // 2 == 3
			max_score = s2[0];
			if (s2[3] > s3[3])
				max_num = 2;

			else if (s2[3] < s3[3]) max_num = 3;
			else { // 3점 횟수가 같을 때
				if (s2[2] > s3[2]) max_num = 2;
				else if (s2[2] < s3[2]) max_num = 3;
				// 2점 횟수도 같을 때 
			}
		}
	}

	cout << max_num << " " << max_score << endl;

	return 0;
}
