#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow_pointer = head;
        ListNode* fast_pointer = head;

        while (fast_pointer && fast_pointer->next) {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
            if (fast_pointer == slow_pointer) return true;
        }
        return false;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);

    a->next = b;
    b->next = c;
    c->next = a;

    Solution sol;
    std::cout << "LeetCode solution result:" << "\n";
    std::cout << sol.hasCycle(a) << "\n";
    return 0;
}