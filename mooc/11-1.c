#include <stdio.h>
#include <stdlib.h>

typedef struct Record{
	char name[11];
	char birthday[11];
	char gender;
	char phone[17];
	char mobile[17];

} Record;

int main()
{
	int N, i, q, num;
	Record* records;
	
	scanf("%d", &N);
	records = (Record*)malloc(sizeof(Record)*N);


	for(i = 0; i < N; ++i){
		scanf("%s %s %c %s %s", records[i].name, records[i].birthday,
			&records[i].gender, &records[i].phone, &records[i].mobile);
	}
	scanf("%d", &q);
	for(i = 0; i < q; ++i){
		scanf("%d", &num);
		if(num < N && num >= 0){
			printf("%s %s %s %c %s\n", records[num].name, records[num].phone,
			records[num].mobile, records[num].gender, records[num].birthday);
		}
		else{
			printf("Not Found\n");
		}
	}

	free(records);

	return 0;


}