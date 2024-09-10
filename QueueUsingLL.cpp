#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};
node *r = NULL;
node *n = NULL;

void enqueue(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->link = NULL;
    if (r == NULL)
    {
        r = temp;
        n = temp;
    }
    else
    {
        r->link = temp;
        r = temp;
    }
}
int dequeue()
{
    if (n == NULL)
    {
        return -1;
    }
    else
    {
        node *temp;
        int data = n->data;
        temp = n;
        n = n->link;
        delete temp;
        return data;
    }
}
int peek()
{
    if (n == NULL)
    {
        return -1;
    }
    else
    {
        int data = n->data;
        return data;
    }
}
bool isempt()
{
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int choice;
    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cin >> data;
            enqueue(data);
            break;

        case 2:
            cout << dequeue() << endl;
            break;
        case 3:
            cout << peek() << endl;
            break;
        case 4:
            cout << isempt() << endl;
            break;
        }
    }
}