// LeetCode 143 - Reorder List
// Approach: Find Middle + Reverse Second Half + Merge Alternately
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
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* firstHalf = head;

        while (secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
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
    sol.reorderList(list1);
    printList(list1); // 1 4 2 3

    ListNode* list2 = buildList({1, 2, 3, 4, 5});
    sol.reorderList(list2);
    printList(list2); // 1 5 2 4 3

    return 0;
}
