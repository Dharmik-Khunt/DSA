#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

// Function to build the tree from level order input
Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node* root = newNode(data);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;
        
        cin >> leftData;
        if (leftData != -1) {
            current->left = newNode(leftData);
            q.push(current->left);
        }
        
        cin >> rightData;
        if (rightData != -1) {
            current->right = newNode(rightData);
            q.push(current->right);
        }
    }

    return root;
}

// A simple function to print leaf nodes of a binary tree
void printLeaves(Node* root) {
    if (root == nullptr) return;
    printLeaves(root->left);
    if (!root->left && !root->right) cout << root->data << " ";
    printLeaves(root->right);
}

// A function to print all left boundary nodes, except a leaf node. Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root) {
    if (root == nullptr) return;
    if (root->left) {
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    } else if (root->right) {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
}

// A function to print all right boundary nodes, except a leaf node. Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root) {
    if (root == nullptr) return;
    if (root->right) {
        printBoundaryRight(root->right);
        cout << root->data << " ";
    } else if (root->left) {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
}

// A function to do boundary traversal of a given binary tree
void printBoundary(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}

// Driver program to test above functions
int main() {
    Node* root = buildTree();
    printBoundary(root);
    return 0;
}