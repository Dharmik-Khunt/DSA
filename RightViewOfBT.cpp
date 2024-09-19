#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *buildTree(int n, int nodes[])
{
    if (n == 0)
        return NULL;

    Node *root = new Node(nodes[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n)
    {
        Node *current = q.front();
        q.pop();

        if (i < n && nodes[i] != -1)
        {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && nodes[i] != -1)
        {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void rightViewUtil(Node *root, int level, int *max_level)
{
    if (root == NULL)
        return;

    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }

    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightViewOfBinaryTree(int n, int nodes[])
{
    Node *root = buildTree(n, nodes);
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
int main()
{
    int n;
    cin >> n;
    int nodes[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }

    rightViewOfBinaryTree(n, nodes);

    return 0;
}