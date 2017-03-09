#include<stdio.h>
int check_pwd();
int main();
{
  if(!check_pwd(1)){
    printf("Password is ture,welcome! \n");
    }
  else
    printf("You are input 3 times worth password ,warning! \n");
  return 0;
}



int check_pwd()
{
  int pwd=0,i=0,n=0;
  int tpwd=12345678;
  for(i=0;i<3;++i){
    printf("please input password: \n");
    scanf("%d\n",&pwd);
    if(pwd==tpwd)
        return 1;
    else
      printf("Password is worth,try again! \n");
      }
    }
