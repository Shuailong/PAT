#include <stdio.h>
#include <math.h>

int main()
{
    int N; // N <= 1000
    char c;
    int level;
    int i, j;
    int remain;

    scanf("%d %c", &N, &c);
    for(level = 0; level*level*2-1 <= N; ++ level);
    level -= 1;
    // level = floor(sqrt((N+1.0)/2.0));
    for(i = level; i >= 1; --i){
        for(j = 0; j < level-i; ++j){
            printf(" ");
        }
        for(j = 0; j < 2*i-2; ++j){
            printf("%c", c);
        }
        printf("%c\n", c);
    }
    for(i = 2; i <= level; ++i){
        for(j = 0; j < level-i; ++j){
            printf(" ");
        }
        for(j = 0; j < 2*i-2; ++j){
            printf("%c", c);
        }
        printf("%c\n", c);
    }
    if(level == 0){
        remain = N;
    }
    else{
        remain = N-level*level*2+1;
    }
    printf("%d\n", remain);
    return 0;
}
         
