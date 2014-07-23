#include <stdio.h>
#include <string.h>

typedef struct Vector
{
	double x;
	double y;
} Vector;

Vector add(Vector v1, Vector v2)
{
	Vector v;
	v.x = v1.x+v2.x;
	v.y = v1.y+v2.y;

	return v;
}

double mabs(double d)
{
	if(d < 0){
		d = -d;
	}

	return d;
}

void print(Vector v)
{
	char sx[5];
	char sy[5];
	int f1 = 0;
	int f2 = 0;

	sprintf(sx, "%.1f", mabs(v.x));
	sprintf(sy, "%.1f", mabs(v.y));

	if(strncmp(sx, "0.0", 3) == 0){
		f1 = 1;
	}
	if(strncmp(sy, "0.0", 3) == 0){
		f2 = 1;
	}

	printf("(");
	if(f1 != 1){
		printf("%.1f", v.x);
	}
	else{
		printf("0.0");
	}
	printf(", ");

	if(f2 != 1){
		printf("%.1f", v.y);
	}
	else{
		printf("0.0");
	}

	printf(")\n");

}

int main()
{
	Vector v1, v2, v;

	scanf("%lf%lf%lf%lf", &v1.x, &v1.y, &v2.x, &v2.y);
	v = add(v1, v2);

	print(v);

	return 0;
}