#include<iostream>
using namespace std;

int main()
{
    int n,i,j;
    int swapped;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    int min_index=0;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(i=0; i<n-1; i++)
    {
        min_index=i;
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
               min_index=j;
            }
        }

        if(min_index!=i)
        {
            swap(a[min_index],a[i]);
        }
    }
    cout<<"Array after sorting: ";
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl<<"23CE058_DHARMIK";
}