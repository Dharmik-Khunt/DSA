#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Insert a node at the front
    void insertAtFront(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Prepared by 23CE058 Dharmik Khunt";
    }

    // Delete a node at the last
    void deleteAtLast()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Prepared by 23CE058 Dharmik Khunt";
    }

    // Delete Nth node from the end
    void deleteNthFromEnd(int n)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *fast = head;
        Node *slow = head;
        for (int i = 0; i < n; ++i)
        {
            if (fast->next == nullptr)
            {
                if (i == n - 1)
                {
                    head = head->next;
                }
                return;
            }
            fast = fast->next;
        }

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        Node *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        cout << "Prepared by 23CE058 Dharmik Khunt";
    }

    // Delete all nodes of the linked list
    void deleteAll()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Prepared by 23CE058 Dharmik Khunt";
    }

    // Display the linked list
    void display()
    {
        cout <<endl<< "Linked List: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << "Prepared by 23CE058 Dharmik Khunt";
    }
};

int main()
{
    SinglyLinkedList list;
    int choice, value, n;

    while (true)
    {
        cout <<endl<< "Menu:\n";
        cout << "1. Insert a node at front\n";
        cout << "2. Delete a node at last\n";
        cout << "3. Delete Nth node from end\n";
        cout << "4. Delete all nodes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtFront(value);
            list.display();
            break;
        case 2:
            list.deleteAtLast();
            list.display();
            break;
        case 3:
            cout << "Enter N (position from end): ";
            cin >> n;
            list.deleteNthFromEnd(n);
            list.display();
            break;
        case 4:
            list.deleteAll();
            list.display();
            break;
        case 5:
            cout << "Prepared by 23CE058 Dharmik Khunt" << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
