#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, X;
	int i;
	int* nums;
	scanf("%d%d", &N,&X);

	nums = (int*)malloc(sizeof(int)*N);
	for(i = 0; i < N; ++i){
		scanf("%d", &nums[i]);
	}

	for(i = 0; i < N; ++i){
		if(nums[i] == X){
			printf("%d\n", i);
			break;
		}
	}
	if(i == N){
		printf("Not Found\n");
	}


	free(nums);
	return 0;
}