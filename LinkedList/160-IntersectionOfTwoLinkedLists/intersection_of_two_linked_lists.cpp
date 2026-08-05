// LeetCode 160 - Intersection of Two Linked Lists
// Approach: Two Pointers (Switch Lists at End)
// Time: O(m+n) | Space: O(1)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a;
    }
};

int main() {
    Solution sol;

    // Build intersecting lists: A=[4,1,8,4,5], B=[5,6,1,8,4,5], intersect at "8"
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* result = sol.getIntersectionNode(headA, headB);
    cout << (result ? result->val : -1) << endl; // 8

    return 0;
}
