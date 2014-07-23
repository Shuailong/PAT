#include <stdio.h>

int main()
{
	int n;
	int i;
	scanf("%d", &n);

	if(n < 10){
		for(i = 1; i <= n; ++i){
			printf("%d", i);
		}
	}
	else if(n < 100){
		for(i = 1; i <= n/10; ++i){
			printf("S");
		}
		for(i = 1; i <= n%10; ++i){
			printf("%d", i);
		}
	}
	else{
		for(i = 1; i <= n/100; ++i){
			printf("B");
		}
		for(i = 1; i <= (n-n/100*100)/10; ++i){
			printf("S");
		}
		for(i = 1; i <= n%10; ++i){
			printf("%d", i);
		}
	}
	printf("\n");

	return 0;
}