#include<stdio.h>

double text(double a[],double m, double x){
	double num = 0;
	int i;
	for (i = 0; i < m; ++i)
	{
		if (x == a[i])
		{
			++num;
		}
	}
	return num;
}
double compare(double a[], double m)
{
	double n = 0;
	int i=0;
	n = a[i];
	for (i = 0; i < m; ++i)
	{
		if (text(a, m, a[i]) < text(a, m, a[i + 1]))
		{
			n = a[i + 1];
		}
	}
	return n;
}
void main()
{
	double a[5];
	int j;
	printf("input 5 integer: \n");
	for (j = 0; j < 5; ++j)
		scanf("%d", &a[j]);
	printf("%.2f", compare(a, 5));
	//return 0;
}
