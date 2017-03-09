#include<stdio.h>

int main()
{
	int a[5],b,s,g,i=0,sz; //"b" is Hundreds , "s" is the tens digit, "g" is Digits, "sz" means number.
	printf("input 5 integer:\n");
	for(i=0;i<5;++i)
		scanf("%d",&a[i]);
		for(i=0;i<5;++i)
		{
			sz=a[i];
			g=sz%10; 
			s=(sz/10)%10;
			b=sz/100;
			if(b>(g+s))
				printf("%d \n",sz);
		}
	return 0;
}
