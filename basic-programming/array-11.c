#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int i;
	int count = 0;
	int* monkeys;
	int alive = 0;
	int king;

	scanf("%d", &N);

	monkeys = (int*)malloc(sizeof(int)*N);
	for(i = 0; i < N; ++i){
		monkeys[i] = 1;
	}
	while(1){
		for(i = 0; i < N; ++i){
			if(monkeys[i] == 1){
				++count;
				if(count%3 == 0){
					monkeys[i] = 0;
				}
			}
		}
		alive = 0;
		for(i = 0; i < N; ++i){
			if(monkeys[i] == 1){
				king = i+1;
				++alive;
			}
		}
		if(alive == 1){
			printf("%d\n", king);
			break;
		}
	}

	free(monkeys);

	return 0;
}