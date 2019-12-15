#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[128];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);


    /*
     * Repeat till all occurrences are replaced. 
     */
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        // Bakup current line
        strcpy(temp, str);

        // Index of current found word
        index = pos - str;

        // Terminate str after word found index
        str[index] = '\0';

        // Concatenate str with new word 
        strcat(str, newWord);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(str, temp + index + owlen);
    }
}


int main(){
	
	FILE *f = fopen("data.txt","r");
	FILE *temp = fopen("replace.txt","w");

	if( f == NULL || temp == NULL){
		printf("Failed to open or read");
		exit(1);
	}
	
	char buffer[128];
	while(fgets(buffer,128,f)){
		replaceAll(buffer,"salam","SSS");
		fputs(buffer,temp);
	}
	
	fclose(f);
	fclose(temp);
	rename("replace.txt","data.txt");

	return 0;
}
