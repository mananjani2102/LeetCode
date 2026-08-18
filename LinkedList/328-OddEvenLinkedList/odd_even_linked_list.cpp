// LeetCode 328 - Odd Even Linked List
// Approach: Two Pointers (In-place)
// Time: O(n) | Space: O(1)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

ListNode* buildList(vector<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    printList(sol.oddEvenList(l1)); // 1 3 5 2 4

    ListNode* l2 = buildList({2, 1, 3, 5, 6, 4, 7});
    printList(sol.oddEvenList(l2)); // 2 3 6 7 1 5 4

    return 0;
}
