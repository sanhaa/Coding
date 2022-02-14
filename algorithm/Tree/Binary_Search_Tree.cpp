// BST 이진탐색트리
// 탐색에 최적화
// 루트노드 기준으로 왼쪽은 작은 값, 오른쪽은 큰 값
#include <iostream>
using namespace std;

struct Node {
	int data = 0;;
	Node* left = 0;
	Node* right = 0;
};

Node *root = nullptr;

// 동적할당 하고 초기화까지 해서 반환
Node* make_node(int val) {
	Node* new_node = new Node;
	if (new_node) {
		new_node->data = val;
		new_node->left = nullptr;
		new_node->right = nullptr;
	}

	return new_node;
}

// key값을 재귀적으로 찾음
Node* Search(Node* node, int key) {
	if (!node) return nullptr;

	if (node->data == key) {
		return node;
	}
	else if (node->data > key) {
		return Search(node->left, key);
	}
	else if (node->data < key) {
		return Search(node->right, key);
	}

	// 찾는 값이 없을 때
	return node; // 이런게 헷갈림..
}

Node* Insert(Node* node, int val) {
	// 삽입의 기본 : 삽입하고자 하는 노드를 찾기(탐색)
	// 탐색 실패 위치에 삽입
	if (!node) {
		Node * new_node = make_node(val);
		return new_node;
	}

	if (node->data < val) {
		node->right = Insert(node->right, val);
	}
	else if (node->data > val) {
		node->left = Insert(node->left, val);

	}
	else {
		// 중복되는 경우 -> 허용 X
		cout << "Duplicated key!" << endl;
	}

	return node;
}

void print_tree(Node* node, int level, int depth) {
	if (node == nullptr) return;
	if (level < depth) return;
	
	print_tree(node->left, level, depth + 1);
	print_tree(node->right, level, depth + 1);

	if (level == depth) {
		printf("%d ", node->data);
	}
}

void print_bst(Node * node) {
	const int depth = 5;
	for (int i = 0; i < depth; i++) {
		print_tree(node, i, 0);
		cout << endl;
	}
	cout << endl;
}

// 현재 서브트리에서 가장 큰 값
Node * find_biggest_node(Node* node) {
	while (node->right != nullptr) {
		node = node->right;
	}

	return node;
}

Node* Delete(Node* node, int val) {
	if (node == nullptr) return nullptr;
	if (node->data < val) {
		node->right = Delete(node->right, val);
	}
	else if (node->data > val) {
		node->left = Delete(node->left, val);
	}
	else {
		// 삭제 대상 노드 찾기
		if (node->left != nullptr && node->right != nullptr) {
			// degree 2 (자식이 두개)
			Node* replace_node = find_biggest_node(node->left);
			node->data = replace_node->data;
			node->left = Delete(node->left, replace_node->data);
		}
		else {
			// degree 0 or 1 (리프노드거나, 자식이 1개)
			Node* delNode = node;
			node = node->left;
			if (node == nullptr) node = delNode-> right;
			delete delNode;
		}
	}
	
	return node;
}

int main() {
	root = Insert(root, 9);
	root = Insert(root, 4);
	root = Insert(root, 12);
	root = Insert(root, 15);
	root = Insert(root, 6);
	root = Insert(root, 3);
	root = Insert(root, 13);
	root = Insert(root, 17);

	print_bst(root);

	//Node*node = Search(root, 6);
	//if (node != nullptr)
	//	printf("0X%p ) %d is founded \n", node, node->data);
	//else
	//	printf("Not found\n");

	cout << "Insert node 5" << endl;
	root = Insert(root, 5);
	print_bst(root);

	cout << "Delete node 13(leaf)" << endl;
	root = Delete(root, 13);
	print_bst(root);

	cout << "Delete node 12(internal)" << endl;
	root = Delete(root, 12);
	print_bst(root);

	cout << "Delete node 9(root)" << endl;
	root = Delete(root, 9);
	print_bst(root);

	return 0;
}
