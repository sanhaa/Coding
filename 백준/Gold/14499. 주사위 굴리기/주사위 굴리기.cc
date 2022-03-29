// BOJ 14499 주사위 굴리기
// 구현
#include <iostream>

using namespace std;

enum DIR {
	EAST=1, WEST, NORTH, SOUTH
};

// Bottom, Front, Right, Top, beHinde, Left
enum PLANE {
	BOT, FRT, RGT, TOP, BHD, LFT
};

const int MAXN = 30; // <= 20;
const int MAXK = 1010;
int map[MAXN][MAXN] = { 0, };
int ops[MAXK] = { 0, };

int dice[6] = { 0, }; // 정육면체 주사위
int hori_rtt[4] = { BOT, RGT, TOP, LFT }; // E - W rotation
int verti_rtt[4] = { BOT, FRT, TOP, BHD }; // N - S rotation
// 동:1 서 북 남
int dr[] = { 0, 0, 0, -1, 1 };
int dc[] = { 0, 1, -1, 0, 0 };

ostream& operator<<(ostream& os, int arr[6]) {
	for (int i = 0; i < 6;i++) {
		os << arr[i] << " ";
	}
	return os;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0, x = 0, y = 0, K = 0;

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];	
	for (int i = 0; i < K; i++) cin >> ops[i];
	
	for (int k = 0; k < K;k++) {
		int move = ops[k];
		int nx = x + dr[move], ny = y + dc[move];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 초과 명령은 무시
		x = nx; y = ny;
		int temp = 0;
		
		if(move == EAST) {
			temp = dice[hori_rtt[0]];
			for (int i = 0; i < 3; i++) {
				dice[hori_rtt[i]] = dice[hori_rtt[i + 1]];
			}
			dice[hori_rtt[3]] = temp; 
		}
		else if (move == WEST) {
			temp = dice[hori_rtt[3]];
			for (int i = 3; i > 0; i--) {
				dice[hori_rtt[i]] = dice[hori_rtt[i - 1]];
			}
			dice[hori_rtt[0]] = temp;
		}
		else if (move == NORTH) {
			temp = dice[verti_rtt[3]];
			for (int i = 3; i > 0; i--) {
				dice[verti_rtt[i]] = dice[verti_rtt[i-1]];
			}
			dice[verti_rtt[0]] = temp;
		}
		else if (move == SOUTH) {
			temp = dice[verti_rtt[0]];
			for (int i = 0; i < 3; i++) {
				dice[verti_rtt[i]] = dice[verti_rtt[i + 1]];
			}
			dice[verti_rtt[3]] = temp;
		}

		if (map[x][y] == 0) {
			map[x][y] = dice[BOT];
		}
		else {
			dice[BOT] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[TOP] << "\n";
		//cout << dice << endl;
	}

	return 0;
}