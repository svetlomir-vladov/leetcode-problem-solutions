#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            auto [node, sum] = q.front();
            q.pop();

            if (!node->left && !node->right && sum == targetSum) return true;
            if (node->left) q.push({node->left, sum + node->left->val});
            if (node->right) q.push({node->right, sum + node->right->val});
        };
        return false;
    };
};

TreeNode* generate_complete_binary_tree(int nodes) {    
    std::queue<TreeNode*> q;
    TreeNode* root = new TreeNode(1);
    q.push(root);
    
    for (int val = 2; val <= nodes;) {
        TreeNode* parent = q.front(); q.pop();
        parent->left = new TreeNode(val++);
        q.push(parent->left);
        if (val <= nodes) {
            parent->right = new TreeNode(val++);
            q.push(parent->right);
        }
    }
    return root;
}

void delete_tree (TreeNode* curr) {
    if (!curr) return;
    delete_tree(curr->left);
    delete_tree(curr->right);
    delete curr;
}

int main() {
    int nodes = 7;
    std::cout << "Generating a complete binary tree with " << nodes << " nodes.\n";
    TreeNode* tree = generate_complete_binary_tree(nodes);

    Solution sol;
    int taget_sum = 7;
    std::cout << "LeetCode solution result:" << "\n";
    std::cout << sol.hasPathSum(tree, taget_sum) << "\n";

    delete_tree(tree);
    return 0;
};