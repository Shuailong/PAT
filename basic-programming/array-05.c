#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char line[41];
	int i;

	fgets(line, sizeof(line), stdin);

	for(i = 0; i < strlen(line); ++i){
		if(line[i] == '#'){
			break;
		}
		if(islower(line[i])){
			putchar(toupper(line[i]));
		}
		else if(isupper(line[i])){
			putchar(tolower(line[i]));
		}
		else{
			putchar(line[i]);
		}
	}

	return 0;
}