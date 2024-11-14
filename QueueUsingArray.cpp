#include <iostream>
using namespace std;
int q[10];
int r = 0;
int f = 0;
int size = 9;
void enqueue()
{
    int i;
    cin >> i;
    if (r == size)
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        q[r] = i;
        r++;
    }
}
int dequeue()
{
    if (r == 0 || r < f)
    {
        return -1;
    }
    else if (r == f)
    {
        int data = q[f];
        r = 0;
        f = 0;
        return -1;
    }
    else
    {
        int data = q[f];
        f++;
        return data;
    }
}
int peek()
{
    if (r == 0)
    {
        return -1;
    }
    else
    {
        return q[f];
    }
}

bool isempty()
{
    if (r == 0)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int choice;
    do
    {
        cout << "1:push \n2:pop\n3:peek\n4:isempty"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            cout << dequeue() << endl;
            break;
        case 3:
            cout << peek() << endl;
            break;
        case 4:
            cout << isempty() << endl;
        }
    }while(choice!=4);
}