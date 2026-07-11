// LeetCode 206 - Reverse Linked List
// Approach: Iterative (Prev, Curr, Next Pointers)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
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
    ListNode* result1 = sol.reverseList(list1);
    printList(result1); // 5 4 3 2 1

    ListNode* list2 = buildList({1, 2});
    ListNode* result2 = sol.reverseList(list2);
    printList(result2); // 2 1

    ListNode* list3 = buildList({});
    ListNode* result3 = sol.reverseList(list3);
    printList(result3); // (empty line)

    return 0;
}
