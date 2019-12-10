#include<stdio.h>
#include<stdlib.h>

struct stack{
	int *buff;
	int buff_size;
	int top;

};

struct stack *init(int size){
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	s->buff = (int*)malloc(sizeof(int)*size);
	s->buff_size = size;
	s->top = -1;
	return s;

}

void push(struct stack *s,int data){
	if(s->top + 1 > s->buff_size)
		return;
	s->top = s->top + 1;
	s->buff[s->top] = data;

}

int top(struct stack *s){
	if(s->top <= -1)
		return -1e9;
	return s->buff[s->top];
	
}

void pop(struct stack *s){
	if(s->top <= -1)
		return;
	s->top = s->top - 1;
	
}

int is_empty(struct stack *s){
	return s->top <= -1;
}

void traverse(struct stack *s){
	for(int i=0;i < s->top;i++){
		printf("%d ",s->buff[i]);
	}
	printf("\n");

}
int main(){
	struct stack *s = init(10);

	push(s,10);
	push(s,20);
	push(s,30);
	push(s,40);
	push(s,50);
	printf("%d",top(s));
	printf("\n");
	pop(s);
	printf("%d",top(s));
	printf("\n");
	
	traverse(s);

	return 0;
}
