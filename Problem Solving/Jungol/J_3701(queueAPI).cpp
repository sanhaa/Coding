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

struct Queue {
	Node*head, *tail;
	int cnt;
}que;

Queue* newQueue() {
	//que.head = NULL;
	//que.tail = NULL;
	//que.cnt = 0;

	return new Queue(); // 이렇게 해??
}

void delQueue(Queue*que) {
	que = NULL;
}

bool empty(Queue*que) {
	return (que->cnt)?false:true; // cnt == 0 -> true
}

int size(Queue*que) {
	return que->cnt;
}

int front(Queue*que) {
	return que->head->num;
}

int back(Queue*que) { // 제일 뒤 노드의 값?
	return que->tail->num;
}

void push(Queue*que, int num) {
	Node*new_node = new Node();
	new_node->num = num;
	new_node->next = NULL;

	if (empty(que) == true) {
		que->head = new_node;
		que->tail = new_node;
	}
	else {
		que->tail->next = new_node;
		que->tail = new_node;
	}

	que->cnt += 1;	
} 

void pop(Queue*que) {
	// empty() 일 때 처리
	if (empty(que) == true) return;
	
	Node*front = que->head->next; // pop 후 front가 될 노드
	que->head = front; 
	que->cnt -= 1;
}


/// === main.cpp ===
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Queue Queue;

extern Queue* newQueue();
extern void delQueue(Queue*que);

extern bool empty(Queue*que);
extern int size(Queue*que);
extern int front(Queue*que);
extern int back(Queue*que);
extern void push(Queue*que, int);
extern void pop(Queue*que);


int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	setbuf(stdout, NULL);

	Queue* que = newQueue();
	int N;
	char cmd[10];
	int num, i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", cmd);
		if (cmd[0] == 'e') {             /// 1. empty
			printf("%d\n", empty(que));
		}
		else if (cmd[0] == 's') {        /// 2. size
			int ret = size(que);
			printf("%d\n", ret);
		}
		else if (cmd[0] == 'f') {        /// 3. front
			if (empty(que)) {
				puts("except!");
			}
			else {
				printf("%d\n", front(que));
			}
		}
		else if (cmd[0] == 'b') {        /// 4. back
			if (empty(que)) {
				puts("except!");
			}
			else {
				printf("%d\n", back(que));
			}
		}
		else {
			if (cmd[1] == 'u') {         /// 5. push
				scanf("%d", &num);
				push(que, num);
			}
			else {                      /// 6. pop
				pop(que);
			}
		}
	}
	delQueue(que);
	return 0;
}

