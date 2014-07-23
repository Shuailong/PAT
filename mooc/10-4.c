#include <stdio.h>
#include <string.h>

int main()
{
	char line[101];
	int N, i;

	gets(line);
	scanf("%d", &N);

	printf("%s", (line+ N % strlen(line)));
	for(i = 0; i < N % strlen(line); ++i){
		putchar(line[i]);
	}
	printf("\n");

	return 0;
}