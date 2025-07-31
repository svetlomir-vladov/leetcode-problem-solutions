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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        std::queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        while (!q.empty()) {
            int q_size = q.size();
            
            for (int i = 0; i < q_size; ++i) {
                TreeNode* root = q.front();
                q.pop();

                if (!root->left && !root->right) {
                    return depth;
                }

                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            depth++;
        }
        return depth;
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
    std::cout << sol.minDepth(tree) << "\n";

    delete_tree(tree);
    return 0;
};