#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a value into the binary tree
void insert(Node *&root, int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        if (value < root->data)
        {
            insert(root->left, value);
        }
        else
        {
            insert(root->right, value);
        }
    }
}

// Perform in-order traversal of the binary tree
void inOrderTraversal(Node *node)
{
    if (node != nullptr)
    {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

// Perform pre-order traversal of the binary tree
void preOrderTraversal(Node *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

// Perform post-order traversal of the binary tree
void postOrderTraversal(Node *node)
{
    if (node != nullptr)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
}

int main()
{
    Node *root = nullptr;
    int numValues;

    cout << "Enter the number of values to insert into the binary tree: ";
    cin >> numValues;

    for (int i = 0; i < numValues; ++i)
    {
        int value;
        cout << "Enter value " << (i + 1) << ": ";
        cin >> value;
        insert(root, value);
    }

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
