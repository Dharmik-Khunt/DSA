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
}
void insertfirst()
{
    int n;
    cout << "Enter int number:";
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
    }
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
int main()
{
    int choice;
    do
    {
        cout << "Enter Choice:";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                insertfirst();
            }
            break;
            case 2:
            {
                DeleteNodeAtFirst();
            }
            break;
            case 3:
            {
                Display();
            }
        }
    } while (choice >= 1 && choice <= 3);

    return 0;
}