#include <stdio.h>

int main()
{
	int times[10];
	int i, j;

	for(i = 0; i < 10; ++i){
		scanf("%d", &times[i]);
	}

	for(i = 1; i < 10; ++i){
		if(times[i]){
			printf("%d", i);
			--times[i];
			break;
		}
	}
	for(i = 0; i < 10; ++i){
		for(j = 0; j < times[i]; ++j){
			printf("%d", i);
		}
	}

	printf("\n");

	return 0;
}