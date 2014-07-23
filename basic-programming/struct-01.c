#include <stdio.h>

typedef struct fraction
{
	int denominator;
	int numerator;
} fraction;


int compare(fraction f1, fraction f2)
{
	 if((double)f1.numerator/f1.denominator < (double)f2.numerator/f2.denominator){
	 	return -1;
	 }
	 else if((double)f1.numerator/f1.denominator > (double)f2.numerator/f2.denominator){
	 	return 1;
	 }

	 return 0;
}



int main()
{
	fraction a, b;

	int cmp;

	scanf("%d/%d %d/%d", &a.numerator, &a.denominator, &b.numerator, &b.denominator);

	cmp = compare(a, b);
	if(cmp == 1){
		printf("%d/%d > %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator);
	}
	else if(cmp == -1){
		printf("%d/%d < %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator);
	}
	else{
		printf("%d/%d = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator);
	}

	return 0;
}
