#include <stdio.h>

long int gcd(long int a, long int b)
{
	long int r;
	while(b > 0){
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

typedef struct Fraction
{
	long int denominator;
	long int numerator;
} Fraction;

Fraction reduce(Fraction f)
{
	Fraction res;
	long int g;

	g = gcd(f.denominator, f.numerator);
	res.numerator = f.numerator/g;
	res.denominator = f.denominator/g;
	
	return res;
}

Fraction add(Fraction f1, Fraction f2)
{
	Fraction f;
	f.denominator = f1.denominator*f2.denominator;
	f.numerator = f1.denominator*f2.numerator + f1.numerator*f2.denominator;

	return reduce(f);
}

int main()
{
	Fraction sum;
	Fraction f;
	int N;
	int i;

	sum.denominator = 1;
	sum.numerator = 0;
	scanf("%d", &N);
	for(i = 0; i < N; ++i){
		scanf("%ld/%ld", &f.numerator, &f.denominator);
		sum = reduce(add(sum, f));
	}
	
	if(sum.numerator % sum.denominator == 0){
		printf("%d\n", sum.numerator/sum.denominator);
	}
	else if(sum.numerator < sum.denominator){
		printf("%ld/%ld\n", sum.numerator, sum.denominator);
	}
	else if(sum.numerator > sum.denominator){
		printf("%ld ", sum.numerator/sum.denominator);
		sum.numerator = sum.numerator%sum.denominator;
		printf("%ld/%ld\n", sum.numerator, sum.denominator);
	}

	return 0;
}