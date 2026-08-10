// LeetCode 203 - Remove Linked List Elements
// Approach: Dummy Node + Skip Matching Nodes
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};

// Helper: array se linked list banao
ListNode* buildList(vector<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) { head = node; tail = node; }
        else { tail->next = node; tail = node; }
    }
    return head;
}

// Helper: linked list print karo
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    ListNode* list1 = buildList({1, 2, 6, 3, 4, 5, 6});
    ListNode* result1 = sol.removeElements(list1, 6);
    printList(result1); // 1 2 3 4 5

    ListNode* list2 = buildList({});
    ListNode* result2 = sol.removeElements(list2, 1);
    printList(result2); // (empty)

    ListNode* list3 = buildList({7, 7, 7, 7});
    ListNode* result3 = sol.removeElements(list3, 7);
    printList(result3); // (empty)

    return 0;
}
