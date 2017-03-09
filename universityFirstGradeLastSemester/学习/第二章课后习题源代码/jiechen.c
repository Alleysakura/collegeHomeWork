//计算阶乘
//
//Copyright since 2016 杨昊憬 1610300a11


#include<stdio.h>

int  main() {
  int n,m=1,i;
  printf("input a number\n");
  scanf("%d",&n);
  for ( i = 1; i<=n; i++) {
    m=m*i;
  }
  printf("%d \n",m );
  return 0;
}
										
