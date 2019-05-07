///////////////////////////////////////
/*
      단순연결리스트 구현하기
									 */
///////////////////////////////////////
//head 최초의 노드를 가리키는 포인터
//리스트 마지막 노드의 포인터 부:NULL
//체인으로 연결된 구조
// 노드= data+link

#include <cstdio>
#include <cstdlib>

//단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct node {
	int data;
	struct node* link;

}node;

//리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	node* head;
}listhead;

//공백 연결 리스트를 생성하는 연산
listhead* create_Listhead(void) {
	listhead* L;
	L = (listhead*)malloc(sizeof(listhead)); //메모리 동적할당
	L->head = NULL; //공백 리스트이므로 다음 노드의 주소값은 NULL
	return L;
}

//노드 생성하는 연산
node* create_Node(int x) {
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->link = NULL;
	return newNode;
}

//노드 찾는 연산
node* search_Node(listhead* L, int x) {
	node* p;
	p = L->head;
	while (p != NULL) {//현재 리스트의 마지막 노드까지 찾음
		if (p->data == x)
			return p;//찾은 노드 반환
		p = p->link;
	}
	return NULL;
}

//노드 삽입하는 연산
void insert_Node(listhead* L, node* preNode, node* newNode) {
	if (L == NULL) {//공백 리스트인 경우
		L->head = newNode; //새 노드를 첫 번째이자 마지막 노드로 연결
	}
	else if (preNode == NULL) {//삽입 위치를 지정하는 포인터 pre가 NULL인 경우
		newNode->link = L->head;
		L->head = newNode;//새 노드를 첫 번째 노드로 삽입
	}
	else {
		newNode->link = L->head;
		L->head = newNode; //새 노드를 첫 번째 노드로 삽입
		preNode->link = newNode;
	}
}

//노드 삭제하는 연산
int remove_Node(listhead* L, int x) {
	node* p;
	node* removeNode;
	p = L->head;

	while (p != NULL) {//현재 리스트의 마지막 노드까지 찾음
		if (p->link != NULL) {
			if (p->link->data == x)
				break;
		}
		p = p->link;
	}
	if (p != NULL) {
		removeNode = p->link; //삭제될 노드를 remove가 가리키게 함
		p->link = removeNode->link;//삭제할 노드 이전노드와 다음 노드 연결
		free(removeNode); //메모리 해제
		return 0;
	}
	else {
		return -1;
	}
}

//노드 순서 뒤집는 연산
void reverse(listhead* L) {
	node* p;//기존 리스트
	node* q;//역순으로 만들 리스트
	node* r;//임시저장 노드

	p = L->head;
	q = NULL;
	r = NULL;
	
	//리스트의 첫번째 노드부터 이동하면서 노드간의 연결을 바꿈
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

//연결 리스트의 전체 메모리를 해제하는 연산
void freelisthead(listhead* L) {
	node* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

//연결 리스트를 순서대로 출력하는 연산
void printList(listhead* L) {
	node* p;
	p = L->head; //p가 첫번째 노드부터

	printf("L=(");
	while (p != NULL) {//마지막 노드까지 하나씩 이동 후 반복문 종료
		printf("%d", p->data);//방문한 노드의 데이터(알파벳 출력)
		p = p->link;//다음노드로 이동
		if (p != NULL) printf(", ");//마지막 노드가 아니라면, 출력
	}
	printf(") \n");
}

int main() {
	listhead* L;
	L = create_Listhead();
	printf("(1) 공백 리스트 생성하기! \n");
	printList(L);
	printf("\n");

	printf("(2) 첫번째 노드에 값 삽입하기! \n");
	insert_Node(L, NULL, create_Node(60)); //60
	printList(L);
	insert_Node(L, NULL, create_Node(50)); //50->60
	printList(L);
	insert_Node(L, NULL, create_Node(30)); //30->50->60
	printList(L);
	insert_Node(L, NULL, create_Node(20)); //20->30->50->60
	printList(L);
	insert_Node(L, NULL, create_Node(10)); //10->20->30->50->60
	printList(L);
	printf("\n");

	printf("(2) 중간노드 30 뒤에 노드 삽입하기! \n");
	node* p = search_Node(L, 30);//데이터가 30인 노드 검색
	insert_Node(L, p, create_Node(40));//검색된 p노드 다음에 40 추가
	printList(L);
	printf("\n");

	printf("(3) 지정된 데이터 값 삭제하기! \n");
	remove_Node(L, 60); //데이터가 60인 노드 삭제
	printList(L);//10->20->30->40->50->60
	printf("\n");

	printf("(4) 리스트를 역순으로 바꾸기! \n");
	reverse(L);
	printList(L);//50->40->30->20->10
	printf("\n");

	printf("(5) 리스트 삭제 \n");
	freelisthead(L);
	printList(L);

	return 0;
}