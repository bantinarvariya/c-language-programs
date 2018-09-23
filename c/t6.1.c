#include<stdio.h>
#include<conio.h>
int main()
{
    int i,t[3];
    for(i=2;i>=0;i--)
t[i]=i-1;
printf("%d",t[1]-t[0]+t[2]);

return 0;
}
