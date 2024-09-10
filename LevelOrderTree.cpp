#include <iostream>
#include <queue>

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


void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
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


    cout << "Level order traversal before deletion: ";
    levelOrder(root);

    cout << "Enter the value to delete from the BST: ";
    cin >> delValue;

    root = deleteNode(root, delValue);

    cout << "Level order traversal after deletion: ";
    levelOrder(root);

    return 0;
}