#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int N, i;
	int* nums;
	scanf("%d", &N);
	int current, previous;
	int max;
	int maxcount = 0;
	int count = 0;

	nums = (int*)malloc(sizeof(int)*N);
	for(i = 0; i < N; ++i){
		scanf("%d", &nums[i]);
	}
	qsort(nums, N, sizeof(int), compare);
	previous = nums[0];
	max = previous;
	for(i = 1; i < N; ++i){
		current = nums[i];
		if(current == previous){
			++count;
		}
		else{
			count = 0;
		}
		if(count > maxcount){
			maxcount = count;
			max = current;
		}

		previous = current;
	}

	printf("%d %d\n", max, maxcount+1);

	free(nums);
	return 0;
}