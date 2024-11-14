#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *link;
} *first1 = NULL, *first2 = NULL, *first3 = NULL;

struct node *create(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
    temp->link = NULL;
    return temp;
}

void InsertNodeAtLast1()
{
    int n;
    cin >> n;
    struct node *temp = create(n);
    struct node *trav = first1;
    if (first1 == NULL)
        first1 = temp;
    else
    {
        while (trav->link != NULL)
        {
            trav = trav->link;
        }
        trav->link = temp;
    }
}
void InsertNodeAtLast2()
{
    int n;
    cin >> n;
    struct node *temp = create(n);
    struct node *trav = first2;
    if (first2 == NULL)
        first2 = temp;
    else
    {
        while (trav->link != NULL)
        {
            trav = trav->link;
        }
        trav->link = temp;
    }
}
void InsertNodeAtLast3(struct node *temp)
{
    struct node *trav = first3;
    if (first3 == NULL)
        first3 = temp;
    else
    {
        while (trav->link != NULL)
        {
            trav = trav->link;
        }
        trav->link = temp;
    }
}

void mergeTwoLinkedLists()
{
    struct node *temp1 = first1;
    struct node *temp2 = first2;
    while (temp1 && temp2)
    {

        if (temp1->info <= temp2->info)
        {
            struct node *temp = create(temp1->info);
            temp1 = temp1->link;
            InsertNodeAtLast3(temp);
        }
        else
        {
            struct node *temp = create(temp2->info);
            temp2 = temp2->link;
            InsertNodeAtLast3(temp);
        }
    }

    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            struct node *temp = create(temp1->info);
            temp1 = temp1->link;
            InsertNodeAtLast3(temp);
        }
    }
    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            struct node *temp = create(temp2->info);
            temp2 = temp2->link;
            InsertNodeAtLast3(temp);
        }
    }
}

void Display(struct node *head)
{
    struct node *trav;
    trav = head;

    if (head == NULL)
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
    int n1, n2;
    cout << "Enter number of nodes in list 1:";
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        InsertNodeAtLast1();
    }
    cout << "Enter number of nodes in list 2:";
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        InsertNodeAtLast2();
    }
    mergeTwoLinkedLists();
    Display(first3);
    return 0;
}
