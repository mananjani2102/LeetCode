// LeetCode 002 - Add Two Numbers
// Approach: Iterative with Carry
// Time: O(max(m, n)) | Space: O(max(m, n))

#include <iostream>
using namespace std;

// ─── Node Definition ───────────────────────────────────────────────
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ─── Solution ──────────────────────────────────────────────────────
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp  = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            temp->next = new ListNode(sum % 10);
            carry      = sum / 10;
            temp       = temp->next;
        }

        return dummy->next;
    }
};

// ─── Helpers ───────────────────────────────────────────────────────
ListNode* buildList(initializer_list<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur   = dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy->next;
}

void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

// ─── Main ──────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // 342 + 465 = 807
    printList(sol.addTwoNumbers(buildList({2,4,3}), buildList({5,6,4})));

    // 0 + 0 = 0
    printList(sol.addTwoNumbers(buildList({0}), buildList({0})));

    // 9999999 + 9999 = 10009998
    printList(sol.addTwoNumbers(buildList({9,9,9,9,9,9,9}), buildList({9,9,9,9})));

    return 0;
}