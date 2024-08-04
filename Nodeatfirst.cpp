#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *link;
} *first = NULL;
struct node *create(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    temp->info = n;
}
void add()
{
    int n;
    cout << "Enter info:";
    cin >> n;
    struct node *temp = create(n);
    struct node *trav = first;

    while (trav->link != NULL)
    {
        trav = trav->link;
    }
    trav->link = temp;
}
void display()
{
    struct node *trav = first;
    if (first == NULL)
    {
        cout << "List is already empty";
        return;
    }
    else
    {
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
    cout << "Enter choice:";
    cin >> choice;

    while (choice >= 0 && choice <= 2)
    {
        switch (choice)
        {
        case 1:
        {
            add();
        }
        break;
        case 2:
        {
            display();
        }
        break;
        }
    }
}
