#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
	FILE *f = fopen("fn8.txt","r");
	/*
	int n;

	printf("Enter the number of lines: ");
	scanf("%d ",&n);	

	char buff[128];
	while( n!=0 ){
		fgets(buff,128,stdin);
		fputs(buff,f);
		n = n - 1;
	}
	*/
	/*
	char c;
	while( c = fgetc(f) != EOF)
		putchar(c);
	*/
	
	char buff[128];
	while(fgets(buff,128,f) != NULL)
		fputs(buff,stdout);
	

	fclose(f);
	return 0;
}
