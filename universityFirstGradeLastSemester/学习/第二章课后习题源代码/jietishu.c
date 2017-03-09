//计算阶梯数
//
//
//
//
//
//Copyright since 2016 杨昊憬，1610300a11


#include<stdio.h>

int main()
{
	int i;
	for (i=1;;i++)
	{
		if((i%2==1)&&(i%3==2)&&(i%5==4)&&(i%6==5)&&(i%7==0))
		{
			printf("%d \n",i);
			break;
		}
	}
	return 0;
}
