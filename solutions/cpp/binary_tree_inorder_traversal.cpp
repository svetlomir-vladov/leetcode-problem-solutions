#include <iostream>
#include <format>
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
    void traverse(TreeNode* curr, std::vector<int>& result) {
        if (!curr) return;
        traverse(curr->left, result);
        result.push_back(curr->val);
        traverse(curr->right, result);
    };
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
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
    TreeNode* binary_tree = generate_complete_binary_tree(7);
    Solution sol;
    std::vector<int> result = sol.inorderTraversal(binary_tree);

    std::cout << "In-order traversal:";
    
    for (const auto& num : result) {
        std::cout << " " << num;
    }
    std::cout << "\n";

    delete_tree(binary_tree);
    return 0;
}   