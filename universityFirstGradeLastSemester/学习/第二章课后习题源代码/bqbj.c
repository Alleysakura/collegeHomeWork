//百钱百鸡问题
//
//g为公鸡，m为母鸡，c为雏鸡
//Copyright since 2016 杨昊憬 1610300a11



#include<stdio.h>

int main()
{
	int g,m,c;
	for (g=1;g<20;g++)
	{
		for (m=1;m<33;m++)
		{
			for (c=3;c<100;c++)
			{
				if ( ((g+m+c)==100 )&&((g*5+m*3+c/3)==100)&&(g>=1)&&(m>=1)&&(c>=3)&&((c%3)==0))
				{
					printf("公鸡 %d,母鸡 %d,雏鸡 %d \n",g,m,c);
				}	
			}
		}
	}
	return 0;
}
