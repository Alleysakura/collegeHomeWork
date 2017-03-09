//九九乘法表
//
//x代表乘数，y代表被乘数
//
//Copyright since 2016 杨昊憬，使用VIM与gcc编译器


#include<stdio.h>

int main()
{
	int x,y,sum;
	printf("________九九乘法表_______\n");
	printf("\n");
	printf("1__2__3__4__5__6__7__8__9\n");
	printf("_________________________\n");
	for(x=1;x<=9;x++){
		for(y=1;y<=9;y++){
			printf("%d ",x*y);
		}
		printf("\n");
	}
	return 0;
}
