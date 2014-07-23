#include <stdio.h>
#include <string.h>
int main()
{
	char line[800];
	char hex[80];
	int i = 0;
	int j = 0;
	long int value = 0;
	int flag = 0;

	memset(line, 0, sizeof(line));
	memset(hex, 0, sizeof(hex));

	fgets(line, sizeof(line), stdin);
	for(i = 0; i < strlen(line); ++i){
		if(line[i] >= '0' && line[i] <= '9'
			|| line[i] >= 'a' && line[i] <= 'f'
			|| line[i] >= 'A' && line[i] <= 'F'){
			hex[j++] = line[i];
		}
		if(line[i] == '-' && flag == 0){
			hex[j++] = line[i];
			flag = 1;
		}
	}
	for(i = 0; i < strlen(hex); ++i){
		if(hex[i] >= '0' && hex[i] <= '9'){
			value = 16*value + hex[i] - '0';
		}
		if(hex[i] >= 'a' && hex[i] <= 'f'){
			value = 16*value + hex[i] - 'a' + 10;
		}
		if(hex[i] >= 'A' && hex[i] <= 'F'){
			value = 16*value + hex[i] - 'A' + 10;
		}
	}

	if(hex[0] == '-' && value != 0){
		printf("-");
	}
	printf("%ld\n", value);
	

	return 0;
}