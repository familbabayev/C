#include<stdio.h>
#include<stdlib.h>

int first_d(int n){
	while (n / 10 != 0){
		n /= 10;
	}

	return n;
}


void quicksort(int arr[],int first,int last){
  	if ( first > last )
		return;
	
	int pivot=first;
	int l=first;
	int r=last;
	int temp;

	while(l < r){
		while(first_d(arr[l]) <= first_d(arr[pivot]))
			l++;
		while(first_d(arr[r]) > first_d(arr[pivot]))
			r--;

		if(l < r){
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
	}

	temp = arr[pivot];
	arr[pivot] = arr[r];
      	arr[r]=temp;
	
	quicksort(arr,first,l-1);
	quicksort(arr,l+1,last);

}


int main(){
	int ls[] = {5,823452,241,44,93,56,36,1,45,34,99,72,11};
	quicksort(ls,0,(sizeof(ls)/sizeof(int)) - 1);
	
	for(int i=0;i < sizeof(ls)/sizeof(int);i++){
		printf("%d ",ls[i]);
	}
	printf("\n");
	for(int i = 0;i < sizeof(ls)/sizeof(int);i++){	
		printf("%d\n",first_d(ls[i]));
	}

	return 0;
}
