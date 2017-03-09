//斐波那契数列
//
//a代表首项，b代表a+1项，c代表a+2项
//
//Copyright since 2016 杨昊憬 1610300a11


#include<stdio.h>

int main()
{
	int x,n,a,b,c;
	printf("please input the number\n");
	scanf("%d",&n);
	a=b=1;
	for(x=1;x<=n+1;x++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("%d \n",a);
	return 0;
}
