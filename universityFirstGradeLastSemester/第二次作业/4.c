#include<stdio.h>

int main() {
  int a[5],i,n;
  printf("input 5 integer: \n");
  for(i=0;i<5;++i){
    scanf("%d",&a[i]);
  }
  for (i=4;i>=0;--i){
    n=a[i];
    printf("%d ",n);
  }
  printf("\n");
  return 0;
}
