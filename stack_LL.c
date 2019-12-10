#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *create(int data){
	struct node *s = (struct node*)malloc(sizeof(struct node));
	s->data = data;
	s->next = NULL;
	return s;
}

void push(struct node **s,int data){
	struct node *nn = create(data);
	if(*s == NULL){
		*s = nn;
		return;
	}
	
	nn->next = *s;
	*s = nn;
		
}

int top(struct node *s){
	if(s == NULL){
		return -1e9;
	}
	return s->data;

}

void pop(struct node **s){
	if(*s == NULL)
		return;

	struct node *temp = *s;
	*s = temp->next;
	temp->next = NULL;
	free(temp);
	
}

void traverse(struct node *s){
	struct node *temp = s;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");

}

int main(){
	struct node *s = NULL;
	
	push(&s,10);
	push(&s,20);
	push(&s,30);
	push(&s,40);
	push(&s,50);

	traverse(s);
	pop(&s);
	pop(&s);
	traverse(s);
	pop(&s);
	pop(&s);
	pop(&s);
	traverse(s);
	pop(&s);


	return 0;
}
