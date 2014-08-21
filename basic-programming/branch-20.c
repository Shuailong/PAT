#include <stdio.h>

int main()
{
    int n;
    int o;
    scanf("%d", &n);

    if(n > 0){
      o = 1;
    }
    else if(n < 0){
      o = -1;
    }
    else{
      o = 0;
    }

    printf("sign(%d) = %d", n, o);

    return 0;
}
