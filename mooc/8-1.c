#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N;
	int* nums;
	int i;
	int times[10];

	for(i = 0; i < 10; ++i){
		times[i] = 0;
	}

	scanf("%d", &N);
	nums = (int*)malloc(sizeof(int)*N);
	for(i = 0; i < N; ++i){
		scanf("%d", &nums[i]);
	}

	for(i = 0; i < N; ++i){
		int num = nums[i];
		while(num){
			int digit = num % 10;
			times[digit]++;
			num /= 10;
		}
	}

	int max = -1;
	for(i = 0; i < 10; ++i){
		if(times[i] > max){
			max = times[i];
		}
	}
	printf("%d:", max);
	for(i = 0; i < 10; ++i){
		if(times[i] == max){
			printf(" %d", i);
		}
	}
	printf("\n");
	
	free(nums);

	return 0;
}