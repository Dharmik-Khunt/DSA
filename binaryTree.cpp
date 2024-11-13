#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insertLeft(int value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            Node* newNode = new Node(value);
            if (root->left == nullptr) {
                root->left = newNode;
            } else {
                newNode->left = root->left;
                root->left = newNode;
            }
        }
    }

    void deleteRight() {
        if (root && root->right) {
            delete root->right;
            root->right = nullptr;
        }
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void levelOrderTraversal(Node* node) {
        if (node == nullptr)
            return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    void displayTraversals() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;

        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;

        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;

        cout << "Level Order Traversal: ";
        levelOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    tree.root = new Node(1);
    tree.insertLeft(2);
    tree.root->right = new Node(3);

    tree.insertLeft(4);

    tree.displayTraversals();

    tree.deleteRight();

    cout << "\nAfter deleting the right node:\n";
    tree.displayTraversals();

cout<<"prepared by 23ce058 dharmik";
    return 0;
}