#include<iostream>
using namespace std;

int main()
{
    int n,j=0,s,a[4][4];
    cout<<"enter any integer\n";
    cin>>n;
    s=n;
    for(int i=0;i<s+15;i++)
    {
        cin>>a[i][j];
        }

    for(int i=0;i<s+15;i++)
    {
          cout<<a[i][j]<<"\t";
        cout<<"\n";
    }
return 0;
}

