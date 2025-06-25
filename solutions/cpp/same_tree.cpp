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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    TreeNode* t1 = generate_complete_binary_tree(7);
    TreeNode* t2 = generate_complete_binary_tree(7);

    Solution sol;
    std::cout << sol.isSameTree(t1, t2) << "\n";

    delete_tree(t1);
    delete_tree(t2);
    return 0;
}