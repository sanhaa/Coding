/// === user.cpp ===

#ifndef NULL
#define NULL 0
#endif
const int SIZE = 100010;
struct Node {
	int num;
	Node* next;
}buf[SIZE];
int bcnt;

struct Stack {
	Node*head;
	int cnt;
}stkObject;

Stack* newStack() {
	return new Stack();
}

void delStack(Stack*stk) {
	stk = NULL;
}

bool empty(Stack*stk) {
	return (stk->cnt == 0);
}

int size(Stack*stk) {
	return stk->cnt;
}

int top(Stack*stk) {
	Node*n = stk->head;
	while (n->next != NULL) { // 마지막 노드 찾기
		n = n->next; 
	}

	return (n->num);
}

void push(Stack*stk, int num) {
	Node*new_node = new Node();
	new_node->num = num;
	new_node->next = NULL;

	Node*n = stk->head;
	if (n == NULL) { // 비어있을 떄
		stk->head = new_node; // 여기
	}
	else {
		while (n->next != NULL) {
			n = n->next;
		}
		n->next = new_node;
	}
	stk->cnt++;
}

void pop(Stack*stk) {
	Node*n = stk->head;
	
	if (n == NULL) return;
	if (n->next == NULL) {
		stk->cnt--;
		stk->head = NULL; return;
	}

	while (n->next->next != NULL) {
		n = n->next;
	}
	n->next = NULL;
	stk->cnt--;
}



/// === main.cpp ===
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Node Node;
typedef struct Stack Stack;

extern Stack* newStack();
extern void delStack(Stack*stk);

extern bool empty(Stack*stk);
extern int size(Stack*stk);
extern int top(Stack*stk);
extern void push(Stack*stk, int);
extern void pop(Stack*stk);


int main() {
	    freopen("input.txt", "r", stdin);
	//    freopen("output.txt", "w", stdout);

	setbuf(stdout, NULL);

	Stack* stk = newStack();
	int N;
	char cmd[10];
	int num, i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", cmd);
		if (cmd[0] == 'e') {             /// 1. empty
			printf("%d\n", empty(stk));
		}
		else if (cmd[0] == 's') {        /// 2. size
			int ret = size(stk);
			printf("%d\n", ret);
		}
		else if (cmd[0] == 't') {        /// 3. top
			if (empty(stk)) {
				puts("except!");
			}
			else {
				printf("%d\n", top(stk));
			}
		}
		else {
			if (cmd[1] == 'u') {         /// 4. push
				scanf("%d", &num);
				push(stk, num);
			}
			else {                      /// 5. pop
				pop(stk);
			}
		}
	}

	delStack(stk);
	return 0;
}
