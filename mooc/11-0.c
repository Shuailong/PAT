#include <stdio.h>
#include <string.h>

double mabs(double f)
{
	if(f < 0){
		return -f;
	}
	else{
		return f;
	}
}
int main()
{
	double x1, y1, x2, y2, sumx, sumy;
  	char ssumx[10];
  	char ssumy[10];

  	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
  	sumx = x1+x2;
  	sumy = y1+y2;

  	sprintf(ssumx, "%.1f", mabs(sumx));
  	sprintf(ssumy, "%.1f", mabs(sumy));
  	printf("(");
  	if(strncmp(ssumx, "0.0", 3) == 0){
  		printf("0.0");
  	}
  	else{
  		printf("%.1f", sumx);
  	}

  	printf(", ");
  	if(strncmp(ssumy, "-0.0", 3) == 0){
  		printf("0.0");
  	}
  	else{
  		printf("%.1f", sumy);
  	}
  	printf(")\n");
  
  	return 0;
}