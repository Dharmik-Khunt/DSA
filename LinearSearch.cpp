#include<iostream>
using namespace std;
int linear_search(int *a,int n,int search_ele)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==search_ele)
        {
            return i;
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
    int search_ele;
    cout<<"Enter the serach element:";
    cin>>search_ele;
    cout<<linear_search(a,n,search_ele);
}
