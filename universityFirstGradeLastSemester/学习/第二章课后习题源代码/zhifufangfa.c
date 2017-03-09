//组合方法
//
//Copyright since 2016 杨昊憬 1610300a11

#include<stdio.h>

int main()
{
	int x,y,z,n=0;
	for(x=1;x<=10;x++)
	{
		for(y=1;y<=10;y++)
		{
			for(z=1;z<=4;z++)
			{
				if (((x+y+z)==10)&&((x+2*y+5*z)==18))
				{
					n=n+1;
				}
			}
		}
	}
	printf("%d \n",n);
	return 0;
}
									
