#include<stdio.h>
int main()
{
    char s[11] = "ABCDE";
    strcat(s+2,"ABCDE");
    printf("%d",s[0]-s[2]);
    return 0;
}
