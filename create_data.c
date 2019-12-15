#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
	
	FILE *file = fopen("data.txt","a");
	

	for (int i = 1;i < argc;i++){
		char c[128];
		strcpy(c,argv[i]);
		fputs("\n",file);
		fputs(c,file);

	}


	fclose(file);



}


