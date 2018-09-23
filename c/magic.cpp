#include<iostream>
using namespace std;
#include<math.h>

int main()
{
    int n,a[4][4];
    cout<<"enter any integer\n";
    cin>>n;
    a[3][3]=n;
    n++;
    a[0][1]=n;
    n++;
    a[0][2]=n;
    n++;
    a[3][0]=n;
    n++;
    a[1][0]=n;
    n++;
    a[2][2]=n;
    n++;
    a[2][1]=n;
    n++;
    a[1][3]=n;
    n++;
    a[2][0]=n;
    n++;
    a[1][2]=n;
    n++;
    a[1][1]=n;
    n++;
    a[2][3]=n;
    n++;
    a[0][3]=n;
    n++;
    a[3][1]=n;
    n++;
    a[3][2]=n;
    n++;
    a[0][0]=n;
    n++;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
          cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
return 0;
}

