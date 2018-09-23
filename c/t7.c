#include<stdio.h>
#include<conio.h>
int main()
{
    int i,t[4]={1,2,4,8};
    for(i=0;i<2;i++)
        t[i]=t[3-i];
    printf("%d\n",t[0]);
    printf("%d\n",t[1]);
    printf("%d\n",t[2]);
    printf("%d\n",t[3]);
    printf("%d\n",t[4]);
}
