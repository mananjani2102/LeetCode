// LeetCode 147 - Insertion Sort List
// Approach: Dummy Node + Insert at Correct Position
// Time: O(n^2) | Space: O(1)

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;

            ListNode* prev = &dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            curr->next = prev->next;
            prev->next = curr;

            curr = next;
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

    ListNode* list1 = buildList({4, 2, 1, 3});
    ListNode* result1 = sol.insertionSortList(list1);
    printList(result1); // 1 2 3 4

    ListNode* list2 = buildList({-1, 5, 3, 4, 0});
    ListNode* result2 = sol.insertionSortList(list2);
    printList(result2); // -1 0 3 4 5

    return 0;
}
