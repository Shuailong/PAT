#include <stdio.h>
#include <string.h>

int main()
{
    char N[1000];
    int i;
    int nums[10];

    scanf("%s", N);
    for(i = 0; i < 10; ++i){
        nums[i] = 0;
    }
    for(i = 0; i < strlen(N); ++i){
        ++nums[N[i]-'0'];
    }

    for(i = 0; i < 10; ++i){
        if(nums[i] != 0){
            printf("%d:%d\n", i, nums[i]);
        }
    }

    return 0;
}
