#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

void list_dir(char *path){
	DIR *dir = opendir(path);
	struct dirent *dir_walk;
	char new_path[128];

	if(!dir)
		return;
	
	while((dir_walk = readdir(dir)) != NULL){
		if(strcmp(dir_walk->d_name,".") != 0 && strcmp(dir_walk->d_name,"..") != 0){
			printf("%s\n",dir_walk->d_name);
			strcpy(new_path,path);
			strcat(new_path,"/");
			strcat(new_path,dir_walk->d_name);
			list_dir(new_path);
		}else{
			printf("%s\n",dir_walk->d_name);	
		}
	
	
	}
	closedir(dir);
}


int main(int argc, char *argv[]){
	if(argc != 2)
		exit(1);
	else{
		char path[128];
		strcpy(path,argv[1]);
		list_dir(path);
	}
	

	return 0;
}
