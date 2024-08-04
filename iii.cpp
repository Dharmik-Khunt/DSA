#include<iostream>
using namespace std;
int row_search(int row,int column, int find,int num[10][10])
{
    int low=0;
    int high=row-1,midr;
    while(low<=high)
    {
        midr=low+(high-low)/2;
        if(num[midr][0]<=find && num[midr][column-1]>=find)
        {
            return midr;
        }
        else if(num[midr][3]<find)
        {
            low=midr+1;
        }
        else
        {
            high=midr-1;
        }
    }
}
int column_search(int *num,int find,int right,int left)
{
    int mid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(num[mid]==find)
        {
            return mid;
        }
        else if(num[mid]<left)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
}
int main()
{
    int r,c;
    cin>>r>>c;
    int a[10][10];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int find;
    cout<<"Enter element that to be search:";
    cin>>find;
    int resultr=row_search(r,c,find,a);
    int resultc=column_search(a[resultr],find,0,c-1);
    cout << resultr << ":rows" << endl;
    cout << resultc << ":colmuns";
    return 0;
}