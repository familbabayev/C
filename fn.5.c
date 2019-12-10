#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *buff;
	int buff_size;
	int first;
	int last;
	int count;	

};

struct queue *create(int size){
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->buff = (int*)malloc(sizeof(int) * size);
	q->buff_size = size;
	q->first = 0;
	q->last = 0;
	q->count = 0;
	return q;

}

void enqueue(struct queue *q,int data){
	if( q->count >= q->buff_size){
		return;	
	}
	q->count = q->count + 1;
	q->buff[q->last] = data;
	q->last = (q->last + 1) % q->buff_size;

}

int dequeue(struct queue *q){
	if( q->count <= 0){
		return -1e9;	
	}
	q->count = q->count - 1;
	q->first = (q->first + 1) % q->buff_size;
	return q->buff[q->first];

}

void traverse(struct queue *q){	
	
	for(int i = q->first,c=0;c < q->count || 0;i = (i + 1) % q->buff_size,c++){
		printf("%d ",q->buff[i]);
	}
	printf("\n");
	
	/*
	int i = q->first;
	int c = 0;
	while (c < q->count){
		printf("%d ",q->buff[i]);
		i = (i + 1) % q->buff_size;
		c++;
	}
	printf("\n");
	*/
	
	/*	
	int i = q->first;      // second way
	int j = q->last;
	
	do{
		printf("%d ",q->buff[i]);
		i = (i + 1) % q->buff_size;
	}while( i != j );

	printf("\n");
	*/
	

}

int main(){
	struct queue *q = create(5);
	traverse(q);
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	enqueue(q,40);
	enqueue(q,50);
	traverse(q);
	dequeue(q);
	dequeue(q);
	enqueue(q,60);
	enqueue(q,70);
	//dequeue(q);
	traverse(q);
	dequeue(q);
	enqueue(q,80);
	traverse(q);

	/*
	int c = q->count;
	for(int i=0;i < c;i++)
		dequeue(q);
	*/
	do{
		dequeue(q);
	}while(q->first != q->last);

	traverse(q);

	return 0;
}
