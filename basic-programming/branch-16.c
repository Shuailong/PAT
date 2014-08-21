#include <stdio.h>
#include <math.h>

int main()
{
    double i;

    scanf("%lf", &i);
    if(i >= 0){
        printf("f(%.2f) = %.2f\n", i, sqrt(i));
    }
    else{
        printf("f(%.2f) = %.2f\n", i, pow((i+1), 2)+2*i+1/i);
    }

    return 0;
  
}
