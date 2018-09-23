#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,x,sum;
    scanf("%d", &n);
       //Complete the code to calculate the sum of the five digits on n.
for(int i=1;i<=5;i++)
{
   // printf("1=%d\n",n);
    x=n%10;
   //  printf("2=%d\n",x);
    sum=sum+x;
   //  printf("sum=%d\n",sum);
    n=n/10;
   //  printf("new n=%d",n);
}
printf("%d",sum);
    return 0;
}
