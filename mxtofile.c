#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct partition{
    int col[128];
    int row[128];
    int r, c;

};

int mx[11][10] = {{1,2,3,4,5,6,7,8,9,10},
        {11,12,13,14,15,16,17,18,19,20},
        {21,22,23,24,25,26,27,28,29,30},
        {31,32,33,34,35,36,37,38,39,40},
        {41,42,43,44,45,46,47,48,49,50},
        {51,52,53,54,55,56,57,58,59,60},
        {61,62,63,64,65,66,67,68,69,70},
        {71,72,73,74,75,76,77,78,79,80},
        {81,82,83,84,85,86,87,88,89,90},
        {91,92,93,94,95,96,97,98,99,100},
        {101,102,103,104,105,106,107,108,109,110}};

void write_file(struct partition *p,int r,int c,int size_r,int size_c){
    int num_files = p->r * p->c;
    
    FILE *files[size_r][size_c];

    for(int i=0; i < size_r/r; i++){
        for(int j=0; j < size_c/c; j++){
            char filename[128];
            sprintf(filename,"file%d%d.txt",i+1,j+1);
            files[i][j] = fopen(filename,"w");
        }
    
    }


    for(int i=0; i < (p->r);i++){
	for(int j=0; j < (p->c); j++){

	    int k = p->row[i];
	    
	    while ( k < p->row[i+1]){
		int l = p->col[j];
	    	while ( l < p->col[j+1] ){
			fprintf(files[i][j],"%d ",mx[k][l]);

			l++;
		}
	        fprintf(files[i][j],"\n");

		k++;

	    }

	    
	}
    }
    
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++)
	    fclose(files[i][j]);
    }

}



struct partition *init_part(int r,int c, int size_r,int size_c){
    struct partition *p = (struct partition*)malloc(sizeof(struct partition));
    p->c = -1;
    p->r = -1;
    int size_r_int = size_r / r;
    int size_c_int = size_c / c;

    int last_r_int = 0;
    int last_c_int = 0;
    for(int i = 0; i <= size_r_int; i++){
        p->r = p->r + 1;
        p->row[p->r] = last_r_int;
        last_r_int += r;
    }

    for(int i = 0; i <= size_c_int; i++){
        p->c = p->c + 1;
        p->col[p->c] = last_c_int;
        last_c_int += c;
    }
    p->row[p->r] = size_r;
    p->col[p->c] = size_c;
    
    return p;
}

int main(){
    struct partition *p = init_part(2,3,11,10);
    write_file(p,2,3,11,10);
    


    return 0;
}
