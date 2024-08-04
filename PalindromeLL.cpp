#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int info;
    struct node *link;
}*head = NULL;

void insert(int n)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = n;
    temp->link = NULL;
    node *trav = head;
    if (trav == NULL)
    {
        head = temp;
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
node *revers(node *head1)
{
    struct node *cur = head1;
    struct node *prev = NULL, *next = NULL;
    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    head1 = prev;
    return head1;
}
bool palidrome(int n)
{
    if (head == NULL || head->link == NULL)
    {
        return true;
    }
    struct node *copy = NULL;
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    copy = revers(slow);

    node *trav = head;
    while (copy != NULL)
    {
        if (trav->info != copy->info)
        {
            return false;
        }
        else
        {
            trav = trav->link;
            copy = copy->link;
        }
    }
    return true;
}
int main()
{
    int n, digit;
    cout << "enter n:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> digit;
        insert(digit);
    }
    bool b = palidrome(n);
    if (b == 1)
    {
        cout << "True";
    }
    else
        cout << "False";

    return 0;
}