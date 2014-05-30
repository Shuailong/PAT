#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int N;
  int i;
  int sum = 0;
  int* nums;
  double avg;
  double item;
  double s = 0;
  double res;
  
  scanf("%d", &N);
  nums = (int*)malloc(sizeof(int)*N);
  for(i = 0; i < N; ++i){
    scanf("%d", nums+i);
    sum += *(nums+i);
  }
  avg = (double)sum/(double)N;
  
  for(i = 0; i < N; ++i){
     item = ((double)nums[i]-avg)*((double)nums[i]-avg);
     s += item;
  }
  res = sqrt(s/(double)N);
  
  printf("%.5f\n", res);
  free(nums);
  return 0;
}
