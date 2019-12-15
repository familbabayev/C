#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
	
	if (argc != 4)
		exit(1);

	char op[80],n1[80],n2[80];

	strcpy(op,argv[1]);
	strcpy(n1,argv[2]);
	strcpy(n2,argv[3]);
	
	float res;
	if(strcmp(op,"sum")==0){
		res = atof(n1) + atof(n2);
	}
	else if(strcmp(op,"sub")==0){
		res = atof(n1) - atof(n2);
	}
	printf("%f\n",res);


	return 0;
}
