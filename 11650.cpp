#include <iostream>
#include <algorithm>

using namespace std;

class Coord {
public:
	int x;
	int y;

	bool operator <(Coord xy) {
		if (this->x == xy.x)
			return this->y < xy.y;
		return this->x < xy.x;
	}
};

int main() {
	int N;
	cin >> N;
	Coord* coords = new Coord[N];
	for (int i = 0; i< N;i++) {
		cin >> coords[i].x >> coords[i].y;
	}
	sort(coords, coords + N);

	for (int i = 0; i < N;i++) {
		cout << coords[i].x << " " << coords[i].y << "\n";
	}

}
