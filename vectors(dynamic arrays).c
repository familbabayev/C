#include<stdio.h>
#include<stdlib.h>

struct vector{
	int *buff;
	int buff_size;
	int pos;
	int start;
	
};

struct vector *create(int size){
	struct vector *v = (struct vector*)malloc(sizeof(struct vector));
	v->buff = (int *)malloc(sizeof(int) * size);
	v->buff_size = size;
	v->pos = -1;
	v->start = 0;
	return v;
	
}

void push(struct vector *v,int data){
	if (v->pos + 1 >= v->buff_size){
		return;
	}
	v->pos = v->pos + 1;
	v->buff[v->pos] = data;

}

int pop(struct vector *v){
	if(v->pos <= -1){
		return -1e9;
	}
	int res = v->buff[v->pos];
	v->pos = v->pos - 1;
	return res;

}

int pop_left(struct vector *v){
	if(v->start > v->pos){
		return -1e9;	
	}
	int res = v->buff[v->start];
	v->start = v->start + 1;
	return res;

}

void traverse(struct vector *v){
	for(int i=v->start;i <= v->pos;i++){
		printf("%d ",v->buff[i]);
	}
	printf("\n");

}


int main(){
	struct vector *v = create(10);
	push(v,10);
	push(v,20);
	push(v,30);
	push(v,40);
	push(v,50);
	push(v,60);

	traverse(v);

	pop(v);
	pop(v);
	pop_left(v);
	pop_left(v);
	
	traverse(v);

	return 0;
}
