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
} *first = NULL;

struct node *create(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
    temp->link = NULL;
    return temp;
}

void insert()
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

void revers()
{
    struct node *prev = NULL;
    struct node *cur = first, *next = first;
    while (next != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    first = prev; // setting head to last node after reversing LL
}

void display()
{
    struct node *trav = first;
    while (trav != NULL)
    {
        cout << trav->info << " ";
        trav = trav->link;
    }
}

int main()
{
    int choice;
    do
    {
        cout <<endl<< "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert();
            display();
            break;
        case 2:
            revers();
            display();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice >= 1 && choice <= 2);

    return 0;
}
