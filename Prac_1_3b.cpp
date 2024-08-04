#include <iostream>
#include <vector>
using namespace std;

int Binarysearch(int arr[], int n, int data)
{
    int right = n, left = 0;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (arr[mid] == data)
        {
            return mid;
        }
        else if (arr[mid] < data)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, data;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> data;

    cout << Binarysearch(arr, n, data) << endl;

    return 0;
}
