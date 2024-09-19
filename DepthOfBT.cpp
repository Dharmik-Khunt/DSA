#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: if the node is null, depth is 0
        }

        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // The depth of the current node is 1 plus the maximum of the left and right depths
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    // Get input from the user
    string input;
    getline(cin, input);

    // Split the input string into vector of nodes
    vector<string> nodes;
    stringstream ss(input);
    string node;
    
    while (getline(ss, node, ' ')) {
        nodes.push_back(node);
    }

    // Build the binary tree
    TreeNode* root = buildTree(nodes);

    // Compute and print the maximum depth
    Solution solution;
    cout<< solution.maxDepth(root) << endl;

    return 0;
}