// LeetCode 82 - Remove Duplicates from Sorted List II
// Approach: Dummy Node + Skip All Duplicates
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
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

    ListNode* list1 = buildList({1, 2, 3, 3, 4, 4, 5});
    ListNode* result1 = sol.deleteDuplicates(list1);
    printList(result1); // 1 2 5

    ListNode* list2 = buildList({1, 1, 1, 2, 3});
    ListNode* result2 = sol.deleteDuplicates(list2);
    printList(result2); // 2 3

    return 0;
}
