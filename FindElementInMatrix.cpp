#include <iostream>
using namespace std;
const int Max_size = 10;
int row_search(int row, int columns, int find, int num[Max_size][Max_size])
{
    int low = 0, high, midr;
    high = row - 1;
    while (low <= high)
    {
        midr = low + (high - low) / 2;
        if (num[midr][0] <= find && num[midr][columns - 1] >= find)
        {
            return midr;
        }
        else if (num[midr][3] < find)
        {
            low = midr + 1;
        }
        else
        {
            high = midr - 1;
        }
    }

    return -1;
}
int column_search(int *num, int find, int left, int right)
{

    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (num[mid] == find)
        {
            return mid;
        }
        else if (num[mid] < find)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

int main()
{
    int r, c;
    cin >> r; 
    cin >> c;
    int a[Max_size][Max_size];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int find;
    cin >> find;

    int resultr = row_search(r, c, find, a);
    int resultc = column_search(a[resultr], find, 0, c - 1);
    cout << resultr << ":rows" << endl;
    cout << resultc << ":colmuns";
}
