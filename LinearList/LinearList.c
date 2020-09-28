#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
#define CAPACITY_STEP 1000
typedef struct LinearList{
	int size;
	int* data;
	int capacity;
}LinearList;


void checkCapacity(struct LinearList* list){
	if(list->size == list->capacity){
		int *p = malloc((list->size + CAPACITY_STEP) * sizeof(int));
		list->capacity = list->capacity + CAPACITY_STEP;
		for(int i = 0; i < list->size; i++){
			p[i] = list->data[i];
		}
		free(list->data);
		list->data = p;
	}
}
LinearList init(){
	LinearList list;
	list.data = malloc(SIZE * sizeof(int));
	list.size = 0;
	list.capacity=SIZE;
	return list;
}
void insert(struct LinearList* list, int data){
	checkCapacity(list);
	list->data[list->size] = data;
	list->size = list->size + 1;
}

void insertTo(struct LinearList* list, int index, int data){
	checkCapacity(list);
	for(int i = list->size; i >= index; i--){
		list->data[i + 1] = list->data[i];
	}
	list->data[index] = data;
	list->size++;
}

void printList(LinearList* list){
	for(int i = 0; i < list->size; i++){
		printf("%d\n", list->data[i]);
	}
}
int size(struct LinearList list){
	return list.size;
}



int main(){
	LinearList list = init();
		for(int i = 0; i < 10; i++){
			insert(&list,i);
		}
		printf("size: %d\n", size(list));
		printf("capacity: %d\n", list.capacity);
		printf("address: %p\n", &(list.data));
		insertTo(&list,5, 2);
		printf("size: %d\n", size(list));
		printf("capacity: %d\n", list.capacity);
		printf("address: %p\n", &(list.data));

		printList(&list);
		return 0;
}
