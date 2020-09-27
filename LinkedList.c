#include<stdio.h>
#include<stdlib.h>
#define INIT_CAPACITY 100

typedef struct DataNode{
    struct DataNode *next;
	struct DataNode *prev;
    int data;
}DataNode;

typedef struct LinkedList{
	 int size;
	 int capacity;
	 DataNode* data;
 }LinkedList;

 void checkCapacity(struct LinkedList* list){
	 if(list->size == list->capacity){
		 DataNode* newData = malloc(sizeof(DataNode) * list->capacity * 2);

		 for(int i = 0; i < list->size; i++){
			 newData[i] = list->data[i];
		 }
		 free(list->data);
		 list->data = newData;
	 }
 }

 LinkedList init(){
	 LinkedList* list;
	 list->data = malloc(sizeof(DataNode) * INIT_CAPACITY);
	 list->size=0;
	 list->capacity=INIT_CAPACITY;
	 return *list;
 }

 void insert(struct LinkedList* list, int data){
	 checkCapacity(list);
	 // 和最后一个元素链接起来
	 DataNode* lastNode = NULL;
	 if(list->size > 0){
		  lastNode = &list[list->size - 1];
	 }
	 DataNode current = {NULL, lastNode, data};
	 if(lastNode != NULL){
		 lastNode->next = &current;
	 } else {

	 }

	 list->size = list->size++;
 }

 void printList(struct LinkedList list){
 	for(int i = 0; i < list.size; i++){
 		printf("%d\n", list.data[i].data);
 	}
 }
 int main(){
	 LinkedList list = init();
	 insert(&list, 1);
	 insert(&list, 2);
	 printList(list);
	 return 0;
 }
