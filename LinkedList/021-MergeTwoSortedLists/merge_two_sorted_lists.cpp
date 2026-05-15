// LeetCode 21 - Merge Two Sorted Lists
// Approach: Dummy Node + Two Pointers
// Time: O(n+m) | Space: O(1)

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
};

// Array se linked list banane ke liye
ListNode* buildList(const vector<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int v : vals) {
        ListNode* node = new ListNode(v);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

// Linked list print karne ke liye
void printList(ListNode* head) {
    while (head) {
        cout << head->val;

        if (head->next)
            cout << " ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    ListNode* list1 = buildList({1, 2, 4});
    ListNode* list2 = buildList({1, 3, 4});
    ListNode* result1 = sol.mergeTwoLists(list1, list2);

    cout << "Merged List 1: ";
    printList(result1);

    // Test Case 2
    ListNode* list3 = buildList({});
    ListNode* list4 = buildList({});
    ListNode* result2 = sol.mergeTwoLists(list3, list4);

    cout << "Merged List 2: ";
    printList(result2);

    // Test Case 3
    ListNode* list5 = buildList({});
    ListNode* list6 = buildList({0});
    ListNode* result3 = sol.mergeTwoLists(list5, list6);

    cout << "Merged List 3: ";
    printList(result3);

    return 0;
}