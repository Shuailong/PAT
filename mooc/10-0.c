#include <stdio.h>
#include <string.h>

int main()
{
	char line[81];
	char word[81];
	int i, j, k;

	j = 0;
	gets(line);
	for(i = strlen(line)-1; i >= 0; --i){
		if(line[i] != ' '){
			word[j++] = line[i];
		}
		else{
			for(k = j-1; k >= 0; --k){
				putchar(word[k]);
			}
			j = 0;
			putchar(' ');
		}
	}
	for(k = j-1; k >= 0; --k){
		putchar(word[k]);
	}
	printf("\n");
	

	return 0;
}