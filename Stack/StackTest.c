#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// ˳���ʵ��ջ
struct Stack{
	int top;
	int* data;
	int length;
	int capacity;
};

// ����ʵ��ջ ��ջ��ջ����ջ��
struct LinkNode{
	int data;
	struct LinkNode* next;
};

struct Stack init(){
	int capacity = 1;
	int* data = (int*)malloc(sizeof(int) * capacity);
	struct Stack stack = {-1, data, 0, capacity};
	return stack;
}



bool push(struct Stack* stack, int data){
	if(stack->length == stack->capacity){
		return false;
	}
	stack->data[++stack->top] = data;
	stack->length = stack->length + 1;
	return true;
}
int pop(struct Stack* stack){
	if(stack->length == 0){
		return -1;
	}
	int data = stack->data[--stack->top];
	stack->length = stack->length - 1;
	return data;
}
void print(struct Stack stack){
	for(int i = stack.length - 1; i >= 0; i--){
		printf("%d\n", stack.data[i]);
	}
}

int main(){
	struct Stack stack = init();
	bool f1 = push(&stack, 1);
	bool f2 = push(&stack, 2);
	printf("%d\n", f2);
	print(stack);
	pop(&stack);
	print(stack);
	return 0;
}
