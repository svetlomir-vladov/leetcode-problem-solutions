#include <iostream>
#include <queue>
#include <algorithm>

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
    int traverse(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(traverse(root->left), traverse(root->right));
    }
public:
    int maxDepth(TreeNode* root) {
        return traverse(root);
    }
};
