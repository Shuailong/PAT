#include <stdio.h>

int main()
{
    int N;
    int count[5];
    int i;

    for(i = 0; i < 5; ++i){
      count[i] = 0;
    }
    scanf("%d", &N);
    for(i = 0; i < N; ++i){
      int grade;
      scanf("%d", &grade);
      if(grade >= 90) count[0]++;
      else if(grade >= 80) count[1]++;
      else if(grade >= 70) count[2]++;
      else if(grade >= 60) count[3]++;
      else count[4]++;
    }

    for(i = 0; i < 4; ++i){
      printf("%d ", count[i]);
    }

    printf("%d", count[i]);

    return 0;
}
