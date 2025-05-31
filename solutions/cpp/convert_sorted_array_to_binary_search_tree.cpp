#include<iostream>
#include<vector>
using namespace std;

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
    TreeNode* createTree(vector<int> nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createTree(nums, start, mid - 1);
        node->right = createTree(nums, mid + 1, end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return createTree(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    Solution sol;
    sol.sortedArrayToBST(nums);
    return 0;
}