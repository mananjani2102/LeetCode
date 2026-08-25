// LeetCode 445 - Add Two Numbers II
// Approach: Stack (avoids reversing the lists)
// Time: O(m+n) | Space: O(m+n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1) { s1.push(l1->val); l1 = l1->next; }
        while (l2) { s2.push(l2->val); l2 = l2->next; }

        int carry = 0;
        ListNode* head = NULL;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) { sum += s1.top(); s1.pop(); }
            if (!s2.empty()) { sum += s2.top(); s2.pop(); }

            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

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

    ListNode* l1 = buildList({7, 2, 4, 3});
    ListNode* l2 = buildList({5, 6, 4});
    printList(sol.addTwoNumbers(l1, l2)); // 7 8 0 7

    ListNode* l3 = buildList({2, 4, 3});
    ListNode* l4 = buildList({5, 6, 4});
    printList(sol.addTwoNumbers(l3, l4)); // 8 0 7

    ListNode* l5 = buildList({0});
    ListNode* l6 = buildList({0});
    printList(sol.addTwoNumbers(l5, l6)); // 0

    return 0;
}
