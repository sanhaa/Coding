/*
Disjoint Set (배열)
*/
#include <iostream>
#define MAX_SIZE 10

int parent[MAX_SIZE] = { 0, };

/* x를 포함하는 루트노드 찾기 */
int findSet(int x) {
	// 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
	if (parent[x] == x) {
		return x;
	}
	else {
		// 각 노드의 부모 노드를 찾아 올라간다.
		return findSet(parent[x]);
	}
}

/* x의 집합과 y의 집합 합치기 */
int unionSet(int x, int y) {
	// 각 원소가 속한 트리의 루트 노드를 찾는다.
	x = findSet(x);
	y = findSet(y);

	if (x < y) { // 작은게 부모가 된다
		parent[y] = x;
		return x;
	}
	else {
		parent[x] = y;
		return y;
	}
}

int main() {
	// init
	for (int i = 1; i < MAX_SIZE; i++) // 1~9 사용
		parent[i] = i;

	unionSet(1, 2);
	unionSet(2, 3);
	unionSet(5, 6);
	unionSet(6, 7);
	unionSet(7, 8);

	for (int i = 1; i < MAX_SIZE; i++) // 1~9 사용
		std::cout << i << " 's parent: " << parent[i] << std::endl;

	std::cout << std::endl;
	std::cout << "1과 5는 같은 집합에 있나? : " << (findSet(1) == findSet(5)) << std::endl;
	std::cout << "5과 6은 같은 집합에 있나? : " << (findSet(6) == findSet(5)) << std::endl;

}
