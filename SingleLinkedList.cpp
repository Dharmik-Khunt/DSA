#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *link;
} *first = NULL;
struct node *create(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
    temp->link = NULL;
    return temp;
}
void InsertNodeAtFirst()
{
    cout << "Enter int number:";
    int n;
    cin >> n;
    struct node *temp = create(n);
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->link = first;
        first = temp;
    }
}
void InsertNodeAtLast()
{
    cout << "Enter int number:";
    int n;
    cin >> n;
    struct node *temp = create(n);
    struct node *trav = first;
    while (trav->link != NULL)
    {
        trav = trav->link;
    }
    trav->link = temp;
}
void InsertBeforeAnInfo()
{
    if (first == NULL)
    {
        cout << "List is Empty...." << endl;
        return;
    }
    int X, n;
    cout << "Enter an element before which you want to add a node:";
    cin >> X;
    cout << "Enter int number :";
    cin >> n;
    struct node *temp = create(n);
    struct node *trav = first;

    if (first->info == X)
    {
        temp->link = first;
        first = temp;
    }
    else
    {
        while (trav->link->info != X)
        {
            trav = trav->link;
        }
        temp->link = trav->link;
        trav->link = temp;
    }
}
void DeleteNodeAtFirst()
{
    if (first == NULL)
    {
        cout << "List is Already empty:" << endl;
        return;
    }
    else if (first->link == NULL)
    {
        struct node *temp = first;
        free(temp);
        cout << "First Node is Deleted" << endl;
        first = NULL;
    }
    else
    {
        struct node *temp = first;
        first = first->link;
        delete (temp);
        cout << "First Node is Deleted" << endl;
    }
}
void DeleteLastNode()
{
    if (first == NULL)
    {
        cout << "List is Already empty:" << endl;
        return;
    }
    else if (first->link == NULL)
    {
        struct node *temp = first;
        free(temp);
        cout << "First Node is Deleted" << endl;
        first = NULL;
    }
    else
    {
        struct node *trav = first;
        while (trav->link->link != NULL)
        {
            trav = trav->link;
        }
        struct node *temp = trav->link;
        trav->link = NULL;
        free(temp);
    }
}
void DeleteAllNodes()
{
    while (first != NULL)
    {
        struct node *temp;  
        if (first->link == NULL)
        {
            temp = first;
            delete (temp);
            first = NULL;
        }
        else
        {
            temp = first;
            first = first->link;
            delete (temp);
        }
    }
    cout << "list is deleted Successfully" << endl;
}
void Display()
{
    struct node *trav;
    trav = first;

    if (first == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    else
    {
        cout << "Data is:";
        while (trav->link != NULL)
        {
            cout << trav->info << " ";
            trav = trav->link;
        }
        cout << trav->info << endl;
    }
}
void menu()
{
    cout << "---------------------------------------------------";
    cout << endl
         << "Enter 1 to insert a node at First" << endl;
    cout << "Enter 2 to insert a node at last" << endl;
    cout << "Enter 3 to insert a node at before an info" << endl;
    cout << "Enter 4 to delete a node at First" << endl;
    cout << "Enter 5 to delete a node at last" << endl;
    cout << "Enter 6 to delete all nodes" << endl;
    cout << "Enter 7 to dispaly all nodes" << endl;
    cout << "Enter 8 to end " << endl;
    cout << "---------------------------------------------------" << endl;
}
int main()
{
    int choice;

    do
    {
        menu();

        cout << "Enter your Choice:";
        cin >> choice;
        //  _flushall();
        switch (choice)
        {
        case 1:
        {
            // cout<<"Insert Node at First:";
            InsertNodeAtFirst();
        }
        break;
        case 2:
        {
            // cout<<"Insert Node at last";
            InsertNodeAtLast();
        }
        break;
        case 3:
        {
            // cout << "Insert a node before an info";
            InsertBeforeAnInfo();
        }
        break;
        case 4:
        {
            // cout << "Delete a node at first";
            DeleteNodeAtFirst();
        }
        break;
        case 5:
        {
            DeleteLastNode();
        }
        break;
        case 6:
        {
            DeleteAllNodes();
        }
        break;
        case 7:
        {
            // cout<<"Display all nodes:";
            Display();
        }
        break;
        case 8:
        {
            exit(0);
        }
        }
    } while (choice >= 1 && choice <= 8);
}
