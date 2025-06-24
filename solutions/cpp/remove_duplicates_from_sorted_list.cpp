#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next;
                delete duplicate;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    Solution sol;
    ListNode* input = new ListNode(1, new ListNode(1, new ListNode (2, new ListNode (3, new ListNode (3)))));

    sol.deleteDuplicates(input);

    while (input) {
        ListNode* temp = input;
        std::cout << temp->val;
        input = input->next;
        delete temp;
    }

    return 0;
}