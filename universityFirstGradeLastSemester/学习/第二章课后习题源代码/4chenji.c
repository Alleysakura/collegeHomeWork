//if判断四种分数
//
//g代表分数
//由于OS X下GCC编译器对“f”十位的识别欠佳，故采用％d的形式，
//相比较书上提供的案例，增加了个位成绩的识别，同时对于100分以上的成绩判定为非法。
//
//Copyright since 2016 杨昊憬，1610300a11


#include<stdio.h>
int main()
{
	printf("input your grades\n");
	int g;
	scanf("%d",&g);
	if (g>100)
	{
		printf("invalid!\n");
	}
	if (g>=90&&g<=100)
	{
		printf("You a straight-a student!very nice!\n");
	}
	if (g<90&&g>=80)
	{
		printf("You are a B student,good!\n");
	}
	if (g<80&&g>=60)
	{
		printf("Oh! You are a C students,just so so.\n");
	}
	if (g<60)
	{
		printf("Opooooooooooos!!!!!!!You are so bad.I will tell you mother!!!!!!!!\n");
	}
	return 0;
}
