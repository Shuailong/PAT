#include <stdio.h>

int gcd(int a, int b)
{
	int r;
	while(b > 0){
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

typedef struct fraction
{
	int denominator;
	int numerator;
} fraction;

fraction reduce(fraction f)
{
	fraction res;
	int g;

	g = gcd(f.denominator, f.numerator);
	res.numerator = f.numerator/g;
	res.denominator = f.denominator/g;
	
	return res;
}

fraction add(fraction f1, fraction f2)
{
	fraction f;
	f.denominator = f1.denominator*f2.denominator;
	f.numerator = f1.denominator*f2.numerator + f1.numerator*f2.denominator;

	return reduce(f);
}



int main()
{
	int N;
	int i;
	fraction sum;

	sum.denominator = 1;
	sum.numerator = 0;

	scanf("%d", &N);

	for(i = 0; i < N; ++i){
		fraction f;
		scanf("%d/%d", &f.numerator, &f.denominator);
		sum = add(sum, f);
	}
	sum.denominator *= N;
	sum = reduce(sum);
	if(sum.denominator == 1){
		printf("%d\n", sum.numerator);
	}
	else{
		printf("%d/%d\n", sum.numerator, sum.denominator);
	}

	return 0;
}
