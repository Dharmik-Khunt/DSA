#include <iostream>
using namespace std;
void menu();
struct node
{
    int info;
    node *lptr;
    node *rptr;
};
struct node *head = NULL, *tail = NULL;

struct node *create(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
    temp->lptr = NULL;
    temp->rptr = NULL;
    return temp;
}
void insert_front()
{
    int n;
    cout << "enter a n :";
    cin >> n;
    struct node *temp = create(n);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->rptr = head;
        head->lptr = temp;
        head = temp;
    }
}
void insert_last()
{
    int n;
    cout << "enter a n :";
    cin >> n;
    struct node *temp = create(n);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->rptr = temp;
        temp->lptr = tail;
        tail = temp;
    }
}
void delete_front()
{
    if (head->rptr == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        struct node *temp = head;
        head = head->rptr;
        free(temp);
    }
}
void delete_last()
{
    if (head->lptr == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        struct node *temp = tail;
        tail = tail->lptr;
        tail->rptr = NULL;
        free(temp);
    }
}
void delete_all()
{

    while (head != NULL)
    {
        head = head->rptr;
        free(head);
    }
}
void insert_info(int pinfo, int n)
{
    struct node *temp = create(n);
    struct node *temp1 = create(n);
    temp1 = head;
    while (temp1->info != pinfo)
    {
        temp1 = temp1->lptr;
    }
    if (temp == NULL || temp->lptr == NULL)
    {
        cout << "Position is out of bounds" << endl;
        return;
    }
    temp->lptr = temp1->lptr;
    temp1->lptr = temp;
    temp->rptr = temp1;
    temp->lptr->rptr = temp;
}
void insert_position()
{
    int n;
    int p;
    cout << "n :";
    cin >> n;
    cout << "position:";
    cin >> p;
    node *trav = new node();
    trav->info = n;

    if (p == 1)
    {
        trav->lptr = head;
        trav->rptr = NULL;
        if (head != NULL)
        {
            (head)->rptr = trav;
        }
        head = trav;
        return;
    }

    node *temp = head;
    for (int i = 1; temp != NULL && i < p - 1; i++)
    {
        temp = temp->lptr;
    }

    if (temp == NULL || temp->lptr == NULL)
    {
        cout << "Position is out of bounds" << endl;
        return;
    }

    trav->lptr = temp->lptr;
    trav->rptr = temp;
    if (temp->lptr != nullptr)
    {
        temp->lptr->rptr = trav;
    }
    temp->lptr = trav;
}
void delet_nth_node(int position)
{
    node *temp = new node();
    temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->lptr;
    }
    temp->rptr->lptr = temp->lptr;
    temp->lptr->rptr = temp->rptr->lptr;
    free(temp);
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->rptr;
    }
    cout << endl;
}
void reversdisplay()
{
    struct node *temp1;
    temp1 = head;
    while (temp1->lptr != NULL)
    {
        temp1 = temp1->lptr;
    }
    struct node *temp;
    temp = temp1;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->rptr;
    }
}

int main()
{
    int n;
    do
    {
        menu();

        cin >> n;
        switch (n)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            cout << "delete all nodes" << endl;
            delete_all();
            break;
        case 6:
            display();
            cout << endl;
            break;
        case 7:
            cout << "rever link list :";
            reversdisplay();
            cout << endl;
            break;
        case 8:
            insert_position();
            break;

        case 9:

            int di;
            int info;

            cout << "n :";
            cin >> di;
            cout << "prev  info :";
            cin >> info;
            insert_info(info, di);
            break;
        case 10:
            int ps;
            cout << "enter a ps :";
            cin >> ps;
            delet_nth_node(ps);

            break;
        case 11:
            exit(0);
        }
    } while (1 <= n && 11 >= n);
    return 0;
}
void menu()
{
    cout << "1. insert at left" << endl;
    cout << "2. insert at right" << endl;
    cout << "3. delete from front" << endl;
    cout << "4. delete from last" << endl;
    cout << "5. delete all nodes" << endl;
    cout << "6. Display link list" << endl;
    cout << "7. Display  revers link list" << endl;
    cout << "8. insert a info with position " << endl;
    cout << "9.insert a after info  :" << endl;
    cout << "10.delet a specific node :" << endl;
    cout << "11. exit" << endl;
}