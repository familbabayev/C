#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;

};

struct node *create(int data){
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}


int length(struct node *head){
	struct node *tmp = head;
	int c = 0;
	while( tmp != NULL){
		tmp = tmp->next;
		c++;
	
	}
	return c;
}

void append(struct node *head,int data){
	struct node *nn = create(data);
	if (head == NULL){
		head = nn;
		return;
	}
	struct node *tmp = head;
	while ( tmp->next != NULL ){
		tmp = tmp->next;
	}
	
	tmp->next = nn;

}

void push(struct node **head,int data,int pos){
	struct node *nn = create(data);
	if (pos > length(*head)){
		printf("Position greater than the length!!!");
	}

	else if (pos == 0){
		nn->next = *head;	
		*head = nn;
	}	

	else{
	struct node *tmp = *head;

	for(int i=0;i < (pos-1);i++){
		tmp = tmp->next;
	
	}
	nn->next = tmp->next;
	tmp->next = nn;
	}
	

}

void traverse(struct node *head){
	struct node *tmp = head;
	if (head == NULL){
		return;
	}
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	
	printf("\n");

}




int main(){
	struct node *head = create(56);
	
	append(head,20);
	append(head,40);
	append(head,50);
	append(head,6);
	traverse(head);
	push(&head,100,5);
	traverse(head);
	printf("%d\n",length(head));
	return 0;
}
