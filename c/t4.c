#include<stdio.h>
#include<conio.h>
void main()
{
    int i,t[5];
    for(i=3;i>=0;i--)
    t[i]=t[4]*i;
    printf("%d",t[0]);
    return 0;
}
