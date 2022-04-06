// BOJ 15683 감시
// 재귀 함수
// 함수에 인자 전달할 때 복사 or 주소값
#include <iostream>
#include <vector>

using namespace std;

struct CCTV {
	int r = 0;
	int c = 0;
	int n = 0; // cctv 종류
	CCTV() {}
	CCTV(int _r, int _c, int _n) {
		r = _r; c = _c; n = _n;
	}
};

const int MAXN = 10;
int N = 0, M = 0;
int ans = MAXN*MAXN; // 최소 사각지대, 사각지대 개수
vector<CCTV> cctvs;
// 1~5번 CCTV의 상하좌우 wathcing info
vector<vector<int>> INFO[6] = {{{0}},
	{{1, 0, 0, 0}, {0,1, 0, 0},{0,0,1,0},{0,0,0,1}},
	{{1,1, 0,0}, {0,0,1,1}},
	{{1, 0, 1, 0},{0,1,0,1},{1,0,0,1},{0,1,1,0}},
	{{1, 1, 1, 0},{1, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 1, 1}},
	{{1, 1, 1, 1}}
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0,0, -1, 1 };

void print_map(vector<vector<int>> map) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void print_info(vector<int> info) {
	for (int i = 0; i < 4; i++) {
		cout << info[i] << " ";
	}
	cout << endl;
}
void backtrack(vector<vector<int>> map, vector<CCTV> cctvs, int cur_i, vector<int> cur_info, int area) {
	if (cur_i != -1) { // 맨 처음 재귀 시작이이 아니면
		CCTV cur = cctvs[cur_i];
		//cout << cur.r << " " << cur.c << " " << cur.n << endl;
		//print_info(cur_info);
		//cout << area << endl;
		// 이번 cctv 감시 정보 - 구역 표시
		for (int d = 0; d < 4; d++) { // 상하좌우 dir
			bool is_watching = cur_info[d]; // 현재 방향 감시 여부
			if (is_watching == 0) continue;

			int nr = cur.r + dr[d], nc = cur.c + dc[d];
			while (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (map[nr][nc] == 0) {
					map[nr][nc] = -1; // 감시중
					area--;
				}
				else if (map[nr][nc] == 6) break;
				nr += dr[d]; nc += dc[d];
			}
		}
		if (ans > area) ans = area; // 최소값 업데이트 
		if (cctvs.size() == cur_i-1) return;
	}
	
	// 다음 CCTV 
	if (cur_i + 1 >= cctvs.size()) return;
	CCTV next = cctvs[cur_i + 1];

	// 다음 CCTV 방향 결정
	vector<vector<int>> infos = INFO[next.n];
	for (vector<int> next_info : infos) {
		backtrack(map, cctvs, cur_i + 1, next_info, area);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0)); // N*M 이차원 벡터
	int area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) area++; // 초기 사각지대 개수
			else if (map[i][j] != 6) {
				cctvs.push_back(CCTV(i, j, map[i][j])); // cctv 좌표, 종류 저장
			}
		}
	}
	ans = area;
	backtrack(map, cctvs, -1, {0,0,0,0}, area);

	cout << ans << "\n";
	return 0;
}