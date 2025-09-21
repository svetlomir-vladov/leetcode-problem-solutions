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
