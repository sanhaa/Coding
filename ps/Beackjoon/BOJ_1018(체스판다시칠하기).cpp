// BOJ 1018 체스판 다시 칠하기
// Brute Force
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 60;
const int MAX_CNT = 64;

int main() {
	int N = 0, M = 0;
	char board[MAX_N][MAX_N] ={0,};
	/* input */
	cin >> N >> M; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++) scanf(" %c", &board[i][j]); // ignore \n character
	}

	int mmin = MAX_CNT;
	// Brute Force
	// try for all start point
	for(int si = 0; si < N; si++){
		for(int sj = 0; sj < M; sj++){
			if(si + 8 > N || sj + 8 > M) continue;
			int cnt = 0; // # of square to be painted again
			// start with 'W'
			char curc = 'W'; // current char 

			for(int i=si;i<si+8;i++){
				for(int j=sj;j<sj+8;j++){
					// set current char by position
					curc = (i + j)%2 == 0 ? 'W' : 'B'; 											
					if(board[i][j] != curc) cnt++;
				}
			}
			// compare with case which starts 'B'
			if(cnt > (MAX_CNT - cnt)) cnt = MAX_CNT - cnt; 

			// update mmin
			mmin = cnt < mmin ? cnt : mmin;
		}
	}

	cout << mmin << endl;

	return 0;
}
