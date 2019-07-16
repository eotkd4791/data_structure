#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _node {
	int data;
	struct _node* next;
}Node;

typedef struct _listStack {
	Node* head;
}Stack;

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return 1;
	else
		return 0;
}

void SPush(Stack* pstack, int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = pstack->head;
	pstack->head = newnode;
}

int SPop(Stack* pstack) {
	int rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

int SPeek(Stack* pstack) {

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}
int main() {
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
	
	return 0;
}