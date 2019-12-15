#include<stdio.h>
#include<stdlib.h>

struct pos{
	int *x;
	int *y;
	int size;
};

struct pos *create(int size){
	struct pos *p = (struct pos*)malloc(sizeof(struct pos));
	p->x = (int*)malloc(sizeof(int) * size);
	p->y = (int*)malloc(sizeof(int) * size);
	p->size =size;
	return p;

}

void quicksort(int arr[],int first,int last){
	if (first > last)
		return;

	int pivot = first;
	int l = first;
	int r = last;
	int temp;

	while( l < r ){
		while ( arr[l] <= arr[pivot])
			l++;
		while (arr[r] > arr[pivot])
			r--;
		if (l < r){
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			
		}

	
	}
	
	temp = arr[pivot];
	arr[pivot] = arr[r];
	arr[r] = temp;
	quicksort(arr,first,r-1);
	quicksort(arr,r+1,last);

}


int main(){
	struct pos *p = create(10);

	int c = 0;
	for(int i = 10; 0 < i;i--){
		p->x[c] = i;
		c++;
	}
	
	c = 0;
	for(int i = 10; 0 < i;i--){
		p->y[c] = i;
		c++;
	}
	quicksort(p->x,0,p->size - 1);
	quicksort(p->y,0,p->size - 1);
	
	for(int i=0;i < p->size ; i++)
		printf("%d ",p->x[i]);
	printf("\n");
	
	for(int i=0;i < p->size ; i++)
		printf("%d ",p->y[i]);
	printf("\n");

	return 0;
}
