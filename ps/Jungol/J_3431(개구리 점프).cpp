#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 100000
#define MAX_Q 100000

struct Log {
	int idx = 0;
	int x1 = 0;
	int x2 = 0;
	int y = 0;
	Log() {};
	Log(int i, int a, int b, int c) {
		idx = i;  x1 = a; x2 = b; y = c;
	}
};

Log logs[MAX_N];
int N = 0, Q = 0;
bool visit[MAX_N] = { 0, };

bool compare(Log l1, Log l2) {
	if (l1.x1 == l2.x1) {
		if (l1.x2 == l2.x2) return l1.y < l2.y;
		else return l1.x2 < l2.x2;
	}
	else
		return l1.x1 < l2.x1;
}
// 점프 하면서 다른 통나무 지나지 않는지
bool check(Log now, Log L) {

	for (int i = 1; i <= N; i++) {
		if (logs[i].idx != L.idx || logs[i].idx != now.idx) continue;
		if (now.y <= L.y) { // 위로 점프
			if (logs[i].y >= now.y && logs[i].y <= L.y) {
				if (logs[i].x1 <= L.x1 || logs[i].x2 >= L.x2) return false;
			}
		}
		else {// 아래로 점프
			if (logs[i].y <= now.y && logs[i].y >= L.y) {
				if (logs[i].x1 <= L.x1 || logs[i].x2 >= L.x2) return false;
			}
		}
	}
	return true;
}

bool answer(Log l1, Log l2) {
	queue<Log> q;

	q.push(l1);
	while (!q.empty()) {
		Log now = q.front(); q.pop();
		visit[now.idx] = true;
		if (now.idx == l2.idx) return true;

		for (int i = 1; i <= N;i++) {
			Log L = logs[i];
			if (L.idx == now.idx || visit[L.idx] == true) continue;
			if ((L.x1 <= now.x2 && L.x1>= now.x1) || (L.x2 >= now.x1  && L.x2 <= now.x2)) {
				// check 점프 가능한지
				if(check(now, L)) q.push(L);
			}
		}
	}
	return false;
}

int main() {
	cin >> N >> Q;

	for (int n = 1; n <= N; n++) { // 1~N
		logs[n].idx = n;
		cin >> logs[n].x1 >> logs[n].x2 >> logs[n].y;
	}

	for (int q = 0; q < Q; q++) {
		int l1, l2;
		cin >> l1 >> l2;
		cout << answer(logs[l1], logs[l2]) << "\n";

		for (int i = 1; i <= N; i++) visit[i] = false;
	}

	return 0;
}
