#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iscontain(char* s1, char* s2)
{
	int i,j;

	for(i = 0; i <= strlen(s1)-strlen(s2); ++i){
		int ti = i;
		int count = 0;
		for(j = 0; j < strlen(s2); ++j){
			if(s1[ti++] == s2[j]){
				++count;
			}
		}
		if(count == strlen(s2)){
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[81], s2[81];
	char temp[81];
	int len,i, j;

	gets(s1);
	gets(s2);
	
	while(iscontain(s1, s2)){
		for(i = 0; i <= strlen(s1)-strlen(s2); ++i){
			int ti = i;
			int count = 0;
			for(j = 0; j < strlen(s2); ++j){
				if(s1[ti++] == s2[j]){
					++count;
				}
			}
			if(count == strlen(s2)){
				strcpy(s1+i, s1+i+strlen(s2));			
			}
		}
	}
	puts(s1);


	return 0;
}