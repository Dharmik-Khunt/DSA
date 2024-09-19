#include <iostream>
#include <map>
#include <cctype>
using namespace std;

class Stack
{
    char *arr = NULL;
    int top;

public:
    Stack()
    {
        arr = new char[100];
        top = -1;
    }

    void push(char n)
    {
        if (top >= 99)
        {
            return;
        }
        arr[++top] = n;
    }

    char pop()
    {
        if (top < 0)
        {
            return -1;
        }
        char val = arr[top--];
        return val;
    }

    char peek()
    {
        if (top < 0)
        {
            return -1;
        }
        return arr[top];
    }

    int isEmpty()
    {
        if (top < 0)
        {
            return 1;
        }
        return 0;
    }
};
int precedence(char ch)
{

    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '(')
    {
        return 4;
    }
}
string convertToPostfix(const string &exp)
{
    string ans;
    Stack s;

    for (char elem : exp)
    {
        if (elem == '(')
        {
            s.push(elem); // a b + c d e - ^ f + * g -
        }
        else if (elem == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                ans += s.pop();
            }
            s.pop();
        }
        else if (isalnum(elem))
        {
            ans += elem;
        }
        else
        {
            while (!s.isEmpty() && precedence(elem) <= precedence(s.peek()))
            {
                ans += s.pop();
            }
            s.push(elem);
        }
    }

    while (!s.isEmpty())
    {
        ans += s.pop();
    }

    return ans;
}

int main()
{

    string exp;
    cin >> exp;

    cout << convertToPostfix(exp);

    return 0;
}