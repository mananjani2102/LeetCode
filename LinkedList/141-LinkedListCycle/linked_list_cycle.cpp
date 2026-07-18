// LeetCode 141 - Linked List Cycle
// Approach: Floyd's Cycle Detection (Fast-Slow Pointer)
// Time: O(n) | Space: O(1)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Test 1: [3,2,0,-4] with cycle at pos=1 → true
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2; // cycle
    cout << sol.hasCycle(n1) << endl; // 1 (true)

    // Test 3: [1] with pos=-1 → false
    ListNode* n5 = new ListNode(1);
    cout << sol.hasCycle(n5) << endl; // 0 (false)

    return 0;
}
