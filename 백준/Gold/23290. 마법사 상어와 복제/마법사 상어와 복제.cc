// BOJ 23290 마법사 상어와 복제
// vector 함수 인자로 전달하기 - call by value, ref 헷갈림
// 이동할 수 있는 방향이 없을 때 이동하지 않는다. != 아무것도 안한다.

#include <iostream>
#include <vector>
using namespace std;

const int N = 5; // 4*4 격자 인덱스 1~4 사용
int M = 0, S = 0;
// fish direction 좌부터 시계방향
int fdr[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }, fdc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };
// shark direction 상 좌 하 우 순서
int sdr[] = { 0, -1, 0, 1, 0 }, sdc[] = { 0, 0,-1, 0, 1 };
pair<int, int> shark;
int smap[N][N] = { 0, }; // 냄새 표시, s번째 연습 표시

void fish_move(vector<int> origin_map[N][N], vector<int> moved_map[N][N]) {

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (origin_map[i][j].size() == 0) continue;
			for (int dir : origin_map[i][j]) {
				int cnt = 0;
				while (cnt < 8) { // 방향 전환
					int nd = dir - cnt; // 반시계 방향 회전
					if (nd <= 0) nd += 8;
					int nr = i + fdr[nd], nc = j + fdc[nd];

					if ((nr == shark.first && nc == shark.second) // 상어 위치 거나
						|| (nr<1 || nr>4||nc<1||nc>4) // 격자 범위 초과
						|| (smap[nr][nc] != 0)) { // 물고기 냄새가 있는 좌표면
						cnt++; continue; // 다음 방향
					}
					// 이동 가능하다면
					moved_map[nr][nc].push_back(nd);
					break;
				}
				if(cnt==8) moved_map[i][j].push_back(dir); // 이동하지 못한 경우 원래 좌표, 방향
			}
		}
	}
}

int max_cnt = -1; // 제거된 물고기 최대 개수
int route[3]; // 상어 루트
int visit[N][N] = { 0, };
// rm_cnt가 최대가 되는 이동 route 구하기
void shark_move(vector<int> moved_map[N][N], int r[3], int depth, int rm_cnt, int s, pair<int, int> sh) {
	// copy 
	vector<int> temp[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = moved_map[i][j];
		}
	}

	if (depth >= 3 ) { // 0, 1, 2로 3번 이동 끝
		if (max_cnt < rm_cnt) {
			max_cnt = rm_cnt;
			for (int i = 0; i < 3; i++) route[i] = r[i];
			// shark = sh;
		}
		return;
	}

	// 나머지 이동
	int temp_s = 0;
	for (int nd = 1; nd <= 4; nd++) {
		r[depth] = nd;
		int nr = sh.first + sdr[nd], nc = sh.second + sdc[nd];
		if (nr < 1 || nr >4 || nc < 1 || nc>4) continue;

		int cur_cnt = rm_cnt + moved_map[nr][nc].size();

		// 물고기 제거
		if (!moved_map[nr][nc].empty()) {
			moved_map[nr][nc].clear();
			// 물고기 냄새 
			//temp_s = smap[nr][nc];
			//smap[nr][nc] = s; // 연습 번호 기록
		}

		shark_move(moved_map, r, depth + 1, cur_cnt, s, make_pair(nr, nc));

		// 원상 복구
		moved_map[nr][nc] = temp[nr][nc];
		//smap[nr][nc] = temp_s;
	}
}

void print_map(vector<int> map[N][N]) {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j].size() == 0) {
				cout << "0";
			}
			else {
				for (int v : map[i][j]) {
					cout << v;
				}
			}
			cout << " ";
		}
		cout << endl;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M >> S;

	vector<int> fmap[N][N]; // 각 좌표에 있는 물고기들 방향 정보
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			fmap[i][j] = vector<int>(0);
	}

	for (int i = 0; i < M; i++) {
		int r = 0, c = 0, d = 0; cin >> r >> c >> d;
		fmap[r][c].push_back(d);
	}

	cin >> shark.first >> shark.second; // 상어 위치
	
	for (int s = 1; s <= S; s++) {

		// init
		max_cnt = -1;
		for (int i = 0; i < 3; i++) route[i] = 0; // init
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) visit[i][j] = 0;

		//print_map(fmap);
		vector<int> moved_map[N][N];
		fish_move(fmap, moved_map); // 물고기들 한 칸씩 이동

		int r[3] = { 0, };
		shark_move(moved_map, r, 0, 0, s, shark);
		// shark 이동 경로만큼 실제 이동
		 
		for (int d = 0; d < 3;d++) {
			int dir = route[d];
			shark.first += sdr[dir]; shark.second += sdc[dir]; // 상어 이동
			// 물고기 제거
			if (!moved_map[shark.first][shark.second].empty()) {
				moved_map[shark.first][shark.second].clear();
				// 물고기 냄새 
				smap[shark.first][shark.second] = s; // 연습 번호 기록
			}
		} 

		// 물고기 냄새 지우기 
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (smap[i][j] == s - 2) smap[i][j] = 0;
			}
		}

		// 물고기 복제
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (fmap[i][j].size() > 0) { // 이동 전의 물고기 (방향) 추가해주기
					moved_map[i][j].insert(moved_map[i][j].begin(), fmap[i][j].begin(), fmap[i][j].end());
				}
			}
		}

		// 다음 연습을 위해 fmap 업데이트
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				fmap[i][j] = moved_map[i][j];
				//copy(moved_map[i][j].begin(), moved_map[i][j].end(), fmap[i][j].begin());
			}
		} 
		//cout << ">>>\n";
		//print_map(fmap);
	}

	// 남아있는 물고기 수
	int ans = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			ans += fmap[i][j].size();
		}
	}
	cout << ans << "\n";

	return 0;
}