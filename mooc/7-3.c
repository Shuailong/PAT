#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
	int i;
	if(n < 2){
		return 0;
	}
	for(i = 2; i <= sqrt(n); ++i){
		if(n % i == 0){
			return 0;
		}
	}

	return 1;

}
int main()
{
	int M, N;
	int num;
	int index;
	int count;
	scanf("%d%d", &M, &N);

	num = 2;
	index = 1;
	count = 0;
	while(1){
		if(isPrime(num)){
			++index;
			if(index > M){
				++count;
				if(count % 10 == 0 || index == N + 1){
					printf("%d\n", num);
				}
				else{
					printf("%d ", num);
				}
			}
		}
		++num;
		if(index > N){
			break;
		}
	}

	return 0;
}