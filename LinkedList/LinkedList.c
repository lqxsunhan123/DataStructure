#include<stdio.h>
#include<stdlib.h>

struct Link{
	int data;
    struct Link* next;
}head,rear;// ͷ�ڵ�

typedef struct Link1{
	int data;
	struct Link1* next;
}Link1;
void init(){
	head.next = &rear;
	rear.next = NULL;
}



// ÿ�ζ�������β�� ����ͷ�ڵ�
Link1* initTail(){
	// ͷָ��
	Link1* p;
	// ͷ�ڵ�
	Link1* head = (Link1*)malloc(sizeof(Link1));
	head->next = NULL;

	// �׽ڵ�
//	Link1* firstNode = (Link1*)malloc(sizeof(Link1));
//	firstNode->data = 1;
//	firstNode->next = NULL;
//	head->next = firstNode;

	// ͷָ��ִ��ͷ�ڵ�
	p = head;

	// ͷָ��
	for(int i = 1; i <=5; i++){
		Link1* node = (Link1*)malloc(sizeof(Link1));
		node->data = i;
		node->next = NULL;

		p->next = node;

		p = node;
	}
	return head;
}

// ÿ�β�����ͷ��
Link1* initHead(){
	// ͷ�ڵ�
	Link1* head = (Link1*)malloc(sizeof(Link1));
	head->next = NULL;

	// �׽ڵ�
//	Link1* firstNode = (Link1*)malloc(sizeof(Link1));
//	firstNode->data = 1;
//	firstNode->next = NULL;
//	head->next = firstNode;


	for(int i = 1; i <=5; i++){
		Link1* node = (Link1*)malloc(sizeof(Link1));
		node->data = i;
		node->next = head->next;
		head->next = node;
	}
	return head;
}



void printLink1(Link1* head){

	Link1* node = head->next;
	while(node){
		printf("%d\n", node->data);
		node = node->next;
	}
}


void tailInsert(struct Link *link, int data){
	struct Link* current = (struct Link*)malloc(sizeof(struct Link));
	current->data = data;

}
struct Link* headInsert(struct Link *link, int data){

	struct Link* current = (struct Link*)malloc(sizeof(struct Link));
	current->data = data;
	current->next = link->next;
	link->next=current;
	link = current;
}
void printList(){
	struct Link* temp = &head;
	temp = temp->next;
	while(temp){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
 int main(){
//	 init();
//	 struct Link* head1 = headInsert(&head, 1);
//	 struct Link* head2 = headInsert(head1, 2);
//	 headInsert(head2, 3);
//	 printList();
//	 headInsert(&head, 4);
//	 headInsert(&head, 5);
//	 printList();

	 Link1* head = initHead();
	 printLink1(head);
	 return 0;
 }
