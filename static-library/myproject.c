#include<stdio.h>
#include "arith.h"
int main()
{

int sum=add(10,50);
  printf("Addition=%d\n",sum);
  int diff=sub(50,10);
   printf("Subtraction=%d\n",diff);
   return 0;
}