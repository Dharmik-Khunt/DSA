#include<iostream>
#include <vector>
using namespace std;

int Binarysearch(int arr[0][0], int size, int element)
{
    int right = size, left = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {

        }
    }
}

int main()
{
    int size;
    int m,n,i,j,element;
    cin>>m>>n;

    int arr[m][n];
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    
    cout<<"Enter element that to be search: ";
    cin>>element;
    size=m*n;
    cout<<Binarysearch(arr,size,element)<<endl;
    return 0;
}