#include<stdio.h>
int main()
{
    int s,i,t[]={0,1,2,3,4,5};
    s=1;

for(i=2;i<6;i+=i+1)
        s+=t[i];
    printf("%d\n",s);
    for(i=2;i<6;i++)
        s+=t[i];
    printf("%d\n",s);
    return 0;
}
