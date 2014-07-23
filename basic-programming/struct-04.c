#include <stdio.h>
#include <stdlib.h>

typedef struct Record
{
  char name[11];
  char birth[11];
  char sex[2];
  char tele[17];
  char mobile[17];
} Record;

int main()
{
    int N, K;
    int i;
    int q;
    
    scanf("%d", &N);
    Record *records = (Record*)malloc(sizeof(Record)*N);
    for(i = 0; i< N; ++i){
      scanf("%s", records[i].name);
      scanf("%s", records[i].birth);
      scanf("%s", records[i].sex);
      scanf("%s", records[i].tele);
      scanf("%s", records[i].mobile);
    }
    
    scanf("%d", &K);
    for(i = 0; i < K; ++i){
      scanf("%d", &q);
      if(q >= 0 && q < N){
        printf("%s %s %s %s %s\n", records[q].name, records[q].tele, 
                records[q].mobile, records[q].sex, records[q].birth);
      }
      else{
        printf("Not Found\n");
      }
    }
    
    free(records);

    return 0;
}
