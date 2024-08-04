#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    int swapped;
    cout << "Enter the size of array:";
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = 1;
            }
            if (swapped = 0)
            {
                break;
            }
        }
    }
    cout << "Array after sorting: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout<<endl<<"23CE058_DHARMIK";
}