#include<iostream>
using namespace std;
int main()
{
    int i,j,k;
    int a[50]={3,1,2,6,9,4};
    cout<<"Enter K:";
    cin>>k;
    for(i=0; a[i]!='\0'; i++)
    {
        for(j=0; a[j]!='\0'; j++)
        {
            if((a[i] + a[j]) % k == 0)
            {
                cout<<"("<<a[i]<<","<<a[j]<<")";
            }
        }
    }
}
