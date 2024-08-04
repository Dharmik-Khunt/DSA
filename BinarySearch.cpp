#include<iostream>
#include<algorithm>
using namespace std;

int binary_search(int left,int right, int *a, int search_ele)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==search_ele)
        {
            return mid;
        }
        else if(a[mid]<search_ele)
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
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);        //It will sort the array 
    int search_ele;
    cout<<"Enter the serach element:";
    cin>>search_ele;
    cout<<binary_search(0,n-1,a,search_ele);
}
