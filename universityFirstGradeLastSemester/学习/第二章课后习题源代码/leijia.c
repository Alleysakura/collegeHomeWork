//累加
//
//Copyright since 2016 杨昊憬



#include <stdio.h>

int main() {
	int n;
	int total=0;
	printf("累加计算");
	printf("input a key:\n");
		scanf("%d",&n);
		while(n!=0)
		{
			total=total+n%10;
			n=n/10;
		}
    printf("%d\n",total);
    return 0;
}
