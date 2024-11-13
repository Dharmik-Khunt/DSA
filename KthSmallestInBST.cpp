#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to construct a binary tree from level-order input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return inorder[k - 1];
    }

private:
    void inorderTraversal(TreeNode* node, vector<int>& inorder) {
        if (!node) return;
        inorderTraversal(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraversal(node->right, inorder);
    }
};

int main() {
    string input;
    getline(cin, input);  // Read input in one line for the tree

    stringstream ss(input);
    vector<string> nodes;
    string node;
    
    // Read tree values
    while (ss >> node) {
        nodes.push_back(node);
    }

    // Build the binary search tree
    TreeNode* root = buildTree(nodes);

    // Input: integer k
    int k;
    cin >> k;

    // Compute and print the kth smallest element
    Solution solution;
    cout << solution.kthSmallest(root, k) << endl;

    return 0;
}