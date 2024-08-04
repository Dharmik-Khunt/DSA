#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(int left, int right, int *a, int ele)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==ele)
        {
            return mid;
        }
        else if(a[mid]<ele)
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
    int i, n, ele;
    cout << "Enter size of array:";
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    cout << "Enter element that to be search:";
    cin >> ele;
    cout << binarysearch(0,n-1,a,ele);
    return 0;
}