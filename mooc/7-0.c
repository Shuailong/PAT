#include <stdio.h>
int main()
{
	char digit;
	int sum = 0;
	const char* nums[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

	while(scanf("%c", &digit), digit != '\n'){
		sum += digit-'0';
	}
	if(sum < 10){
		printf("%s\n", nums[sum]);
	}
	else if(sum < 100){
		printf("%s %s\n", nums[sum/10], nums[sum%10]);
	}
	else{
		printf("%s %s %s\n", nums[sum/100], nums[(sum-sum/100*100)/10], nums[sum%10]);
	}

	return 0;
}