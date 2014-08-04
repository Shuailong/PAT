#include <stdio.h>
#include <string.h>

char* substr(char* line, char* sub)
{
	p = strstr(line, sub);
	if(p == NULL){
		break;
	}
	for(i = 0; i < p-line; ++i){
		buff[i] = line[i];
	}
	strcat(buff, p+strlen(sub));
	return buff;
}

int main()
{
	char line[81];
	char sub[81];
	int i, j;
	char *p;
	char *q;
	int pos;
	char buff[81];

	gets(line);
	gets(sub);

	p = line;
	for(j = 0; j < 3; ++j){
		p = substr(p, sub);
	}
	puts(p);

	return 0;
}