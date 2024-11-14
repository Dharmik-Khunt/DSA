#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
}*r=NULL, *n=NULL;
struct node *create(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data= n;
    temp->link = NULL;
}

void enqueue()
{
    int no;
    cout << "Enter int number:";
    cin >> no;
    struct node *temp = create(no);
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
bool isempty()
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
    do
    {
        cout << "1:push \n2:pop\n3:peek\n4:isempty" << endl;
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
    } while (choice != 4);
}