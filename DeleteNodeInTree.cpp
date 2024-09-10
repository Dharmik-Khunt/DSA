#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }


    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
       
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

     
        Node* temp = findMin(root->right);

     
        root->data = temp->data;

      
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, value, delValue;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values to insert into the BST: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }


    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    
    cout << "Enter the value to delete from the BST: ";
    cin >> delValue;

    root = deleteNode(root, delValue);


    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}