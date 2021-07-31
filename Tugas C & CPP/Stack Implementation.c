#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	unsigned cap;
	int* array;
};

struct stack* create(unsigned cap){
	struct stack * stack = (struct stack*)malloc(sizeof(struct stack));
	stack -> cap = cap;
	stack -> top = -1;
	stack -> array = (int*)malloc(stack->cap * sizeof(int));
	return stack;
}

int full(struct stack* stack){
	return stack -> top == stack -> cap -1;
}

int empt(struct stack* stack){
	return stack -> top == -1;
}

void push(struct stack* stack, int item){
	if(fulll(stack)){
		return;
	}
	stack -> array[++stack -> top] = item;
	printf("%d masuk ke dalam stack\n", item);
}

int pop(struct stack* stack){
	if(emp(stack)){
		return INT_MIN;
	return stack -> array[stack -> top--];
	}
} 
int peek(struct stack* stack){
	if(emp(stack)){
		return INT_MIN;
	}
	return stack -> array[stack -> top];
}
					
int main(){
	struct stack* stack = create(100);
	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	
	printf("%d terhapus dari stack\n", pop(stack));
	
	return 0;
}
