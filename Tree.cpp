#include <iostream>
#include <queue> // For level-order insertion

using namespace std;

// Node structure for the tree
class Node
{
public:
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

// Binary Tree class
class BinaryTree
{
public:
    Node *root;

    BinaryTree() { root = nullptr; }

    // Insert nodes in level order based on user input
    void insert(int data)
    {
        Node *newNode = new Node(data);

        // If the tree is empty, make the new node the root
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        // Level-order insertion using a queue
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            // Check for the first available left child spot
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
            }

            // Check for the first available right child spot
            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    // Preorder traversal (Root -> Left -> Right)
    void preorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Inorder traversal (Left -> Root -> Right)
    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Postorder traversal (Left -> Right -> Root)
    void postorder(Node *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Perform traversal based on user choice
    void performTraversal(int choice)
    {
        switch (choice)
        {
        case 1:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
};

int main()
{
    BinaryTree tree;
    int n, value, traversalChoice;

    // Get the number of nodes to be inserted
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Insert nodes into the tree
    cout << "Enter the values to insert into the tree:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        tree.insert(value);
    }

    // Let the user choose the type of traversal
    cout << "*" << endl;
    cout << "Choose traversal" << endl;
    cout << "1.Preorder" << endl;
    cout << "2.Postorder" << endl;
    cout << "3.Inorder" << endl;
    cout << "*" << endl;

    cin >> traversalChoice;

    // Perform the traversal based on user choice
    tree.performTraversal(traversalChoice);

    return 0;
}