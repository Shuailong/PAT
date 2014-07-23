#include <stdio.h>

// Problem: overflow
int main()
{
	int A, N;
	int i;
	int sum = 0;
	int item;
	int fac1, fac2;
	
	scanf("%d%d", &A, &N);
	
	fac1 = A;
	fac2 = N;
	for(i = 1; i <= N; ++i){
		item = fac1*fac2;
		sum += item;
		fac1 *= 10;
		--fac2;
	}
	printf("%d\n", sum);
	return 0;
}
