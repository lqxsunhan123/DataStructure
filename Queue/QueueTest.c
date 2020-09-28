#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 链表实现队列 先进先出


typedef struct LinkQueueNode{
	int data;
	struct LinkQueueNode* prev;
	struct LinkQueueNode* next;
}Node;


Node* init(){
	// 头节点
	Node* head = (Node*)malloc(sizeof(Node));
	// 尾节点
	Node* rear = (Node*)malloc(sizeof(Node));
	head->next = rear;
	rear->prev = head;
	return head;
}

bool push(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;
	head->next->prev = node;

	head->next = node;
	node->prev = head;
	return true;
}


Node* pop(Node* rear){
	printf("%d", rear->prev->data);
	Node* node = rear->prev;
	node->prev->next = rear;
	rear->prev = node->prev;
	return node;
}
void print(Node* head){
	Node* tmp = head->next;
	while(tmp && tmp->next){
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}


int main(){
	Node* head = init();
	Node* rear = head->next;
	push(head, 1);
	push(head, 2);

	print(head);


	//Node* node = pop(&rear);
	//printf("%d\n", node->data);
	return 0;
}
