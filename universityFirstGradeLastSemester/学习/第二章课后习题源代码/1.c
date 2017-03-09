#include<stdio.h>
int main()
{
	int i,j=0,s=0,n=4;
	for (i=1;i<=n;i++)
	{
		j=j+1;
		s=s+j;
	}
	printf("s=%d\n",s);
	return 0;
}
