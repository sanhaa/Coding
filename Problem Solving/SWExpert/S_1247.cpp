// S_1247 #
#include <iostream>
using namespace std;

#define INT_MAX 1000
#define SIZE 12  // 최대 장소 개수 (집+회사+고객) 
#define ABS(x) (((x)<0)?-(x):(x)) // 간단한 계산은 매크로 이용
#define MIN(a, b) ((a)<(b)?(a):(b))

// x,y 로 표현될 position 구조체 정의
struct pos {
	int x = 0;
	int y = 0;
	pos() {};
	pos(int _x, int _y) {
		x = _x; y = _y;
	}
};

// global variable
int N = 0; // 고객수
int memo[SIZE][SIZE] = { 0, }; // 각 장소 사이의 거리
pos place[SIZE]; // 회사, 고객들, 집 위치 모두 저장
int min_dist = INT_MAX;

// 인덱스에 해당하는 두 장소 사이의 거리
// 이미 계산한 값이 있으면 이용
int calculate_dist(int i, int j) {
	if (memo[i][j] > 0) return memo[i][j];
	pos a = place[i], b = place[j];
	return memo[i][j] = memo[j][i] = ABS(a.x - b.x) + ABS(a.y - b.y);
}

// 백트래킹
// visit 배열대신 비트마스크 사용
void recursive(int visit, int now, int dist) {
	if (visit == (1 << N + 1) - 1) { // 종료조건 : 모든 place를 방문했을 때
		min_dist = MIN(min_dist, dist + calculate_dist(now, N + 1));// min 업데이트
		return;

	}
	if (dist >= min_dist) return; // 최소값보다 거리가 크면 더이상 탐색할 필요 X

	for (int i = 1;i <= N;i++) {
		if (!(visit & (1 << i)) && now != i) {
			recursive((visit | (1 << i)), i, dist + calculate_dist(i, now));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("1247_input.txt", "r", stdin);

	int T = 0;
	cin >> T;

	for (int t = 1;t <= T;t++) {
		// 테스트케이스 반복시 변수 초기화
		min_dist = INT_MAX;
		N = 0;
		fill_n(place, SIZE, pos(0, 0));
		for (int i = 0;i < sizeof(memo);i++) *((char*)memo + i) = 0;

		// input
		cin >> N;
		cin >> place[0].x >> place[0].y; // 첫번째 장소는 회사
		cin >> place[N + 1].x >> place[N + 1].y; // N+1 번째 장소는 집

		for (int i = 1;i <= N;i++) {
			cin >> place[i].x >> place[i].y;
		}

		recursive(1, 0, 0);
		cout << '#' << t << " " << min_dist << "\n";
	}

	return 0;
}
