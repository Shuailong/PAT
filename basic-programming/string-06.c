#include <stdio.h>
#include <string.h>

int convert(char* binary)
{
	int i;
	int res = 0;

	for(i = 0; i < 8; ++i){
		res = res*2 + (binary[i]-'0');
	}

	return res;
}

int main()
{
	char ip[33];
	char ip1[9];
	char ip2[9];
	char ip3[9];
	char ip4[9];

	scanf("%s", ip);
	strncpy(ip1, ip, 8);
	strncpy(ip2, ip+8, 8);
	strncpy(ip3, ip+16, 8);
	strncpy(ip4, ip+24, 8);
	printf("%d.%d.%d.%d\n", convert(ip1), convert(ip2), convert(ip3), convert(ip4));

	return 0;
}