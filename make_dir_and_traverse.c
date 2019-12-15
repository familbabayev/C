#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>

int main(){
	mkdir("TEST",0700);
	
	DIR *dir = opendir("c_final");
	
	struct dirent *dir_walk;

	while((dir_walk = readdir(dir)) != NULL){
		printf("%s\n",dir_walk->d_name);
	}

	
	return 0;
}
