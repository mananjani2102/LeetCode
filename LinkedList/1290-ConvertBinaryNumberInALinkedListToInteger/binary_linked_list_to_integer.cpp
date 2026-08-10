// LeetCode 1290 - Convert Binary Number in a Linked List to Integer
// Approach: Bit Shifting While Traversing
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
    int getDecimalValue(ListNode* head) {
        int result = 0;

        while (head) {
            result = (result << 1) | head->val;
            head = head->next;
        }

        return result;
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

int main() {
    Solution sol;

    ListNode* list1 = buildList({1, 0, 1});
    cout << sol.getDecimalValue(list1) << endl; // 5

    ListNode* list2 = buildList({0});
    cout << sol.getDecimalValue(list2) << endl; // 0

    return 0;
}
