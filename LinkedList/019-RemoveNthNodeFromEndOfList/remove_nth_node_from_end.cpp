// LeetCode 19 - Remove Nth Node From End of List
// Approach: Two Pointers (Fast-Slow with Gap) - One Pass
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

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

    ListNode* list1 = buildList({1, 2, 3, 4, 5});
    ListNode* result1 = sol.removeNthFromEnd(list1, 2);
    printList(result1); // 1 2 3 5

    ListNode* list2 = buildList({1});
    ListNode* result2 = sol.removeNthFromEnd(list2, 1);
    printList(result2); // (empty)

    ListNode* list3 = buildList({1, 2});
    ListNode* result3 = sol.removeNthFromEnd(list3, 1);
    printList(result3); // 1

    return 0;
}
