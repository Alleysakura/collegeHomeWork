#include<stdio.h>

int main() {
  int d=0,x,a[5],n,i;  // "d" is max number "x" is min number
  printf("input 5 integer: \n");
  for(i=0;i<5;++i)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<5;++i)
  {
    n=a[i];
    if(n>d)
      d=n;   //find the max number.
  }
  int x=d;  //give the max number to the initial value for min number.
  for(i=0;i<5;++i)
  {
    n=a[i];
    if(n<x)
      x=n;  //find the min number.
  }
  printf("max=%d min=%d \n",d,x);
  return 0;
}
