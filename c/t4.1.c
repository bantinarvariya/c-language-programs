#include<stdio.h>
#include<conio.h>
void main()
{
    int i,t[5];
    for(i=3;i>=0;i--)
    t[i]=t[4]*i;
    printf("%d\n",t[3]);
    printf("%d\n",t[2]);
    printf("%d\n",t[1]);
    printf("%d\n",t[0]);
    return 0;
}
