#include<stdio.h>
#include<stdlib.h>

int mx[32][32];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < m ; j++){
			scanf("%d",&mx[i][j]);
		}
	
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < m ; j++){
			printf("%d ",mx[i][j]);
		}
		printf("\n");
	}
	
	int max = mx[0][0];
	int min = mx[0][0];
	
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < m ; j++){
			if(mx[i][j] > max){
				max = mx[i][j];
			}
			if(mx[i][j] < min){
				min = mx[i][j];
			}
		}
	printf("%d %d\n",max,min);



	return 0;
}
