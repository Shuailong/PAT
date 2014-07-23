#include <stdio.h>
#include <string.h>

int main()
{
	char line[81];
	char c;
	int i;

	gets(line);
	c = getchar();
	for(i = 0; i < strlen(line); ++i){
		if(line[i] == c){
			puts(line+i);
			break;
		}
	}
	if(i == strlen(line)){
		printf("Not found\n");
	}

	return 0;
}