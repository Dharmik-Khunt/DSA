#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    // (a) Insert a node in BST
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    // (b) Search a node in BST
    TreeNode* search(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }
        if (val < root->val) {
            return search(root->left, val);
        }
        return search(root->right, val);
    }

    // Helper function to perform an in-order traversal to find the kth smallest element
    void inorder(TreeNode* root, int& k, int& result) {
        if (root == nullptr) {
            return;
        }

        // Traverse the left subtree
        inorder(root->left, k, result);

        // Decrease k, and if k == 0, we have found the kth smallest element
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }

        // Traverse the right subtree
        inorder(root->right, k, result);
    }

    // Kth smallest element in BST
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root, k, result);
        return result;
    }
};

// Use case with user input
int main() {
    BST bst;
    TreeNode* root = nullptr;
    int n, value, k;

    // (a) Insert nodes into the BST (from user input)
    cout << "Enter the number of nodes to insert into the BST: ";
    cin >> n;
    cout << "Enter the node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = bst.insert(root, value);
    }

    // (b) Search for a node (from user input)
    cout << "Enter the value to search in the BST: ";
    cin >> value;
    TreeNode* searchResult = bst.search(root, value);
    if (searchResult) {
        cout << "Node with value " << value << " found: " << searchResult->val << endl;
    } else {
        cout << "Node with value " << value << " not found." << endl;
    }

    // Kth smallest element (from user input)
    cout << "Enter the value of k to find the kth smallest element in the BST: ";
    cin >> k;
    int kthSmallestValue = bst.kthSmallest(root, k);
    if (kthSmallestValue != -1) {
        cout << "The " << k << "th smallest value in the BST is: " << kthSmallestValue << endl;
    } else {
        cout << "Kth smallest element not found." << endl;
    }

    return 0;
}