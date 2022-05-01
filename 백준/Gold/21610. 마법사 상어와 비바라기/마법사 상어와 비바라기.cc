// BOJ 21610: 마법사 상어와 비바라기
#include <iostream>

using namespace std;

const int MAXN = 60; // <= 50
int dr[] = { 0,0,-1,-1,-1,0,1,1,1 }, dc[] = { 0,-1,-1,0,1,1,1,0,-1 };

int A[MAXN][MAXN] = { 0, }, clouds[MAXN][MAXN] = { 0, };
int N = 0, M = 0;


void print_arr() {
	cout << "A: " << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << clouds[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----\n";
}

void copy(int src[MAXN][MAXN], int dst[MAXN][MAXN]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void init_arr(int arr[MAXN][MAXN]) {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) arr[i][j] = 0;
	}
}

void move(int d, int s) {

	int new_clouds[MAXN][MAXN] = { 0, };

	// 구름 이동
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (clouds[i][j] == 1) {
				int ni = i + dr[d] * s, nj = j + dc[d]*s;
				// 넘어가는 범위 처리
				while (ni < 1) ni += N; while (ni > N) ni -= N;
				while (nj < 1) nj += N; while (nj > N) nj -= N;

				A[ni][nj] += 1; // 2. 비 내리기
				new_clouds[ni][nj] = 1;  // 3. 이동한 구름 (제거됨)
			}
		}
	}

	// 4. 대각선 바구니 탐색, 물 복사
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) { 
			if (new_clouds[i][j] == 1) { // 이번에 비 내린 칸
				int cnt = 0; // 대각선 방향 물 들어있는 바구니 개수
				for (int k = 2; k <= 8; k += 2) {
					int ni = i + dr[k], nj = j + dc[k];
					if (ni<1 || nj<1 || ni>N || nj>N) continue;
					if (A[ni][nj] >= 1) cnt++;
				}
				A[i][j] += cnt;
			}
		}
	}

	// clouds init
	init_arr(clouds);

	// 5. 구름 생성
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] >= 2) {
				if (new_clouds[i][j] == 1) clouds[i][j] = 0; // 이번에 구름이 있었던 자리면 생성되지 않음
				else {
					clouds[i][j] = 1;
					A[i][j] -= 2;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	// INIT
	N = 0; M = 0;
	init_arr(A);
	init_arr(clouds);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}

	// 초기 구름 4개
	clouds[N][1] = 1; clouds[N][2] = 1;
	clouds[N - 1][1] = 1; clouds[N - 1][2] = 1;

	// M 번의 이동 명령
	for (int i = 0; i < M; i++) {
		int d = 0, s = 0; cin >> d >> s;
		move(d, s);
	}

	// 물의 양의 합
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) ans += A[i][j];
	}
	cout << ans << "\n";

	return 0;
}