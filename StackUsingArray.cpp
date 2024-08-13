#include <iostream>
using namespace std;
void push(int Stack[], int size, int &top)
{
    int n;
    cin >> n;
    if (top == size)
        cout << "Stack Overflow";
    else
    {
        top++;
        Stack[top] = n;
    }
}
int pop(int Stack[], int size, int &top)
{
    if (top == 0)
    {
        cout << "Stack Underflow";
    }
    else
    {
        int x = Stack[top];
        top--;
        return x;
    }
}
void display(int Stack[], int size, int &top)
{
    while (top != 0)
    {
        cout << " " << Stack[top];
        top--;
    }
    cout << endl;
}
int main()
{
    int size, top = 0;
    cout << "Enter size of an Array:";
    cin >> size;
    int Stack[size];
    int choice;

    do
    {
        cout << "Enter 1 to enter data in Stack" << endl
             << "Enter 2 to pop data from the stack" << endl
             << "Enter 3 to display stack data" << endl
             << "Enter 4 to end" << endl;
        cout << "Enter your Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            push(Stack, size, top);
        }
        break;
        case 2:
        {
            cout << "poped data is:" << pop(Stack, size, top) << endl;
        }
        break;
        case 3:
        {
            display(Stack, size, top);
        }
        break;
        case 4:
        {
            exit(0);
        }
        break;
        default:
        {
            cout << "Enter valid option";
        }
        }

    } while (choice != 4);

    return 0;
}