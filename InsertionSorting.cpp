#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    int temp;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(i=1; i<n; i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }

    cout<<"Array after sorting: ";
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl<<"23CE058_DHARMIK";
}