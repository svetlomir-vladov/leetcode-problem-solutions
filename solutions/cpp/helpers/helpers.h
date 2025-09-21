#ifndef HELPERS_H
#define HELPERS_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* generate_complete_binary_tree(int nodes);
void delete_tree (TreeNode* curr);

ListNode* generate_linked_list(int arr[], int size);
void print_linked_list(ListNode* head);
void delete_linked_list(ListNode* head);

#endif