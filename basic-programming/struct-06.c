#include <stdio.h>
#include <string.h>

typedef struct Complex
{
	double real;
	double imagine;
} Complex;

Complex add(Complex c1, Complex c2)
{
	Complex res;

	res.real = c1.real + c2.real;
	res.imagine = c1.imagine + c2.imagine;

	return res;
}

Complex minus(Complex c1, Complex c2)
{
	Complex res;

	res.real = c1.real - c2.real;
	res.imagine = c1.imagine - c2.imagine;

	return res;
}

// (a+bi)*(c+di) = (ac-bd)+(ad+bc)i
Complex multiply(Complex c1, Complex c2)
{
	Complex res;

	res.real = c1.real*c2.real-c1.imagine*c2.imagine;
	res.imagine = c1.real*c2.imagine+c1.imagine*c2.real;

	return res;
}

// (a+bi)/(c+di) = (a+bi)(c-di)/(c^2+d^2) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
Complex divide(Complex c1, Complex c2)
{
	Complex res;

	res.real = (c1.real*c2.real+c1.imagine*c2.imagine)/(c2.real*c2.real+c2.imagine*c2.imagine);
	res.imagine = (c1.imagine*c2.real-c1.real*c2.imagine)/(c2.real*c2.real+c2.imagine*c2.imagine);

	return res;
}

double dabs(double d)
{
	if(d < 0){
		d = -d;
	}

	return d;
}

void print(Complex c)
{
	char sreal[5];
	char simagine[5];
	int t1 = 0;
	int t2 = 0;

	memset(sreal, 0, sizeof(sreal));
	memset(simagine, 0, sizeof(simagine));

	sprintf(sreal, "%.1f", dabs(c.real));
	sprintf(simagine, "%.1f", dabs(c.imagine));

	//printf("real: %s  imagine: %s\n", sreal, simagine);

	if(strncmp(sreal, "0.0", 3) == 0){
		t1 = 1;
	}
	if(strncmp(simagine, "0.0", 3) == 0){
		t2 = 1;
	}

	if(t1 && !t2){
		printf("%.1fi\n", c.imagine);
	}
	else if(!t1 && t2){
		printf("%.1f\n", c.real);
	}
	else if(t1 && t2){
		printf("0.0\n");
	}
	else{
		printf("%.1f%+.1fi\n", c.real, c.imagine);
	}
}

int main()
{
	Complex a, b;
	Complex sum, difference, product, quotient;

	scanf("%lf%lf%lf%lf", &a.real, &a.imagine, &b.real, &b.imagine);
	sum = add(a, b);
	difference = minus(a, b);
	product = multiply(a, b);
	quotient = divide(a, b);

	printf("(%.1f%+.1fi) + (%.1f%+.1fi) = ", a.real, a.imagine, b.real, b.imagine);
	print(sum);
	printf("(%.1f%+.1fi) - (%.1f%+.1fi) = ", a.real, a.imagine, b.real, b.imagine);
	print(difference);
	printf("(%.1f%+.1fi) * (%.1f%+.1fi) = ", a.real, a.imagine, b.real, b.imagine);
	print(product);
	printf("(%.1f%+.1fi) / (%.1f%+.1fi) = ", a.real, a.imagine, b.real, b.imagine);
	print(quotient);

	return 0;
}