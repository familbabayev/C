#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *rep_str(char *s,char *old,char *new1){
    char *ret;
    int i, count = 0;
    int newlen = strlen(new1);
    int oldlen = strlen(old);
 
    for (i = 0; s[i] != '\0'; i++)    
    {
        if (strstr(&s[i], old) == &s[i]) 
        {
            count++;
            i += oldlen - 1;
        }
    }
    ret = (char *)malloc(i + count * (newlen - oldlen));
    if (ret == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    while (*s)
    {
        if (strstr(s, old) == s) //compare the substring with the newstring
        {
            strcpy(&ret[i], new1);
            i += newlen; //adding newlength to the new string
            s += oldlen;//adding the same old length the old string
        }
        else
        ret[i++] = *s++;
    }
    ret[i] = '\0';
    return ret;
}


int main(){
	char str[] = "salam necesen yaxssiyam salam men de yaxsiyam sag olsalamat qal.";
	char c[] = "salam";
	char d[] = "SSS";

	printf("Old str: %s\n",str);
	char *res = NULL;
	res = rep_str(str,c,d);
	printf("New str: %s\n",res);
	
	free(res);
	return 0;
}
