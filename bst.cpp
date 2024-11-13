#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left = NULL;
    struct node *right = NULL;
};

node *create() {
    int x;
    cout << "Enter the value (-1 to stop): ";
    cin >> x;

    if (x == -1) {
        return NULL;
    }

    node *p = new node;
    p->data = x;

    cout << "Left child of " << x << ": ";
    p->left = create();

    cout << "Right child of " << x << ": ";
    p->right = create();

    return p;
}

node* binary(node* root, int value) {
    if (root == NULL) {
        node* newNode = new node();
        newNode->data = value;
        return newNode;
    }
    if (value < root->data) {
        root->left = binary(root->left, value);
    } else if (value > root->data) {
        root->right = binary(root->right, value);
    }
    return root;
}

struct node* searchtree(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchtree(root->left, value);
    }

    return searchtree(root->right, value);
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    node *root = NULL;

    root = create();

    int k;
    cout << "Enter a value to insert into the binary search tree: ";
    cin >> k;
    root = binary(root, k);

    cout << "Inorder traversal of the tree: ";
    inorder(root);
    cout << endl;

    int searchVal;
    cout << "Enter a value to search in the binary search tree: ";
    cin >> searchVal;
    node* searchResult = searchtree(root, searchVal);

    if (searchResult != NULL) {
        cout << "Value " << searchVal << " found in the tree." << endl;
    } else {
        cout << "Value " << searchVal << " not found in the tree." << endl;
    }

cout<<"prepared by 23ce058 dharmik";
    return 0;
}