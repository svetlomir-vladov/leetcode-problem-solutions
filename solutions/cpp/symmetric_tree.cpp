#include <iostream>
#include <vector>
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
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left || !right) return left == right;
        return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
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
    TreeNode* tree = generate_complete_binary_tree(7);

    Solution sol;
    std::cout << sol.isSymmetric(tree) << "\n";

    delete_tree(tree);
    return 0;
}