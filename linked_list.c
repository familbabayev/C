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

int len(struct node *head){
	struct node *temp = head;
	int c = 0;
	while(temp != NULL){
		temp = temp->next;
		c++;
	}

	return c;
}

void append(struct node **head,int data){
	struct node *nn = create(data);

	if (*head == NULL){
		*head = nn;
		return;
	}

	struct node *temp = *head;
	while( temp->next != NULL){
		temp = temp->next;
	}
	temp->next = nn;

}

void insert(struct node **head,int data,int pos){
	struct node *nn = create(data);
	if(*head == NULL){
		*head = nn;
		return;
	}
	if(pos > len(*head))
		return;

	else if(pos == 1){
		nn->next = *head;
		*head = nn;
	}

	else{
		struct node *temp = *head;
		int c = 0;
		while( c < pos - 2){
			temp = temp->next;
			c++;
		}
			
		nn->next = temp->next;
		temp->next = nn;

	}


}

void delete_node(struct node **head,int data){
	struct node *prev = *head;
	if(prev->data == data){
		*head = prev->next;
		prev->next = NULL;
		free(prev);
		return;
	}

	while(prev->next->data != data){
		prev = prev->next;
	}
	if(prev == NULL)
		return;

	struct node *temp = prev->next;
	prev->next = temp->next;
	temp->next = NULL;
	free(temp);


};

void delete_by_pos(struct node **head,int pos){
	struct node *temp = *head;
	if(*head == NULL || pos > len(*head) )
		return;
	
	else if(pos == 1){
		*head = temp->next;
		temp->next = NULL;
		free(temp);
		return;

	}
	else{
		struct node *prev = *head;
		int c = 0;
		while(c < pos-2){
			prev = prev->next;
			c++;
		}
		temp = prev->next;
		prev->next = temp->next;
		temp->next = NULL;
		free(temp);
	
	}

}

void traverse(struct node *head){
	struct node *temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void traverse_rec(struct node *head){
	if(head == NULL){
		printf("\n");
		return;
	}
	printf("%d ",head->data);
	traverse_rec(head->next);
}


void reverse(struct node **head){
	if (head == NULL){
		return;
	}
	struct node *prev = NULL;
	struct node *curr = *head;
	struct node *next = NULL;

	while ( curr != NULL ){
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;

	}
	*head = prev;

}


int main(){
	struct node *head = NULL;
	traverse_rec(head);	
	insert(&head,88,100);

	traverse(head);
	append(&head,-10);
	traverse(head);
	insert(&head,99,1);
	traverse(head);
	append(&head,10);
	traverse(head);
	append(&head,20);
	traverse(head);
	append(&head,30);
	traverse(head);
	insert(&head,15,2);
	traverse(head);
	printf("%d \n",len(head));
	insert(&head,100,len(head)+3);
	
	delete_by_pos(&head,1);
	traverse_rec(head);
	delete_node(&head,88);
	delete_node(&head,15);
	delete_node(&head,30);
	traverse(head);
	reverse(&head);
	traverse(head);
	

	return 0;
}
