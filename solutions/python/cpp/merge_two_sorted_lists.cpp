#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode mergedList(0);
            ListNode* current = &mergedList;
            
            while (list1 && list2) {
                if (list1->val <= list2->val) {
                    current->next = list1;
                    list1 = list1->next;
                }
                else {
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;
            }
            current->next = list1 ? list1 : list2;
            return mergedList.next;
        }
    };

ListNode* createLinkedList(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test Case 1: list1 = [1, 3, 5], list2 = [2, 4, 6]
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    ListNode* list1 = createLinkedList(arr1, 3);
    ListNode* list2 = createLinkedList(arr2, 3);

    cout << "List 1: ";
    printLinkedList(list1);
    cout << "List 2: ";
    printLinkedList(list2);

    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printLinkedList(mergedList);
    deleteLinkedList(mergedList);
    return 0;
}