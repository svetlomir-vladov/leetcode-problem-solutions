#include "helpers.h"
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* generate_linked_list(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

void delete_linked_list(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}