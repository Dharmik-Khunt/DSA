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
void insertlast()
{
    int n;
    cin >> n;
    struct node *temp = create(n);
    struct node *trav = first;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        while (trav->link != NULL)
        {
            trav = trav->link;
        }
        trav->link = temp;
    }
}
int deletemiddle(struct node *first)
{
    if (first == NULL && first->link == NULL)
    {
        cout << "List is empty";
    }
    struct node *slow = first;
    struct node *fast = first;
    struct node *prev = NULL;
    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        prev = slow;
        slow = slow->link;
    }
    // cout<<prev->info<<endl;
    prev->link=slow->link; 

}
int display(struct node *first)
{
    struct node *trav = first;
    if (first == NULL)
    {
        cout << "Already Empty";
    }
    else
    {
        while (trav->link != NULL)
        {
            cout << trav->info << " ";
            trav = trav->link;
        }
        cout<<trav->info;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        insertlast();
    }
    deletemiddle(first);
    display(first);
    return 0;
}