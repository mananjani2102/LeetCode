// LeetCode 24 - Swap Nodes in Pairs
// Approach: Dummy Node + Pointer Manipulation
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
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

    ListNode* list1 = buildList({1, 2, 3, 4});
    ListNode* result1 = sol.swapPairs(list1);
    printList(result1); // 2 1 4 3

    ListNode* list2 = buildList({});
    ListNode* result2 = sol.swapPairs(list2);
    printList(result2); // (empty)

    ListNode* list3 = buildList({1});
    ListNode* result3 = sol.swapPairs(list3);
    printList(result3); // 1

    ListNode* list4 = buildList({1, 2, 3});
    ListNode* result4 = sol.swapPairs(list4);
    printList(result4); // 2 1 3

    return 0;
}
