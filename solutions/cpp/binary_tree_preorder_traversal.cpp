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
private:
    void traverse(TreeNode* curr, std::vector<int>& result) {
        if (!curr) return;
        traverse(curr->left, result);
        result.push_back(curr->val);
        traverse(curr->right, result);
    };
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    };
};
