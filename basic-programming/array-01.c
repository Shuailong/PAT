#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char line[81];
	int i;
	long res = 0;;

	fgets(line, sizeof(line), stdin);
	for(i = 0; i < strlen(line); ++i){
		if(isdigit(line[i])){
			res = res * 10 + line[i]-'0';
		}
	}
	printf("%ld\n", res);	

	return 0;
}