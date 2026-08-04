// LeetCode 237 - Delete Node in a Linked List
// Approach: Copy Next Node's Value, Skip Next Node
// Time: O(1) | Space: O(1)

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Helper: array se linked list banao
ListNode* buildList(vector<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        ListNode* newNode = new ListNode(v);
        if (!head) { head = newNode; tail = newNode; }
        else { tail->next = newNode; tail = newNode; }
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

    ListNode* list1 = buildList({4, 5, 1, 9});
    ListNode* nodeToDelete1 = list1->next; // node with value 5
    sol.deleteNode(nodeToDelete1);
    printList(list1); // 4 1 9

    ListNode* list2 = buildList({4, 5, 1, 9});
    ListNode* nodeToDelete2 = list2->next->next; // node with value 1
    sol.deleteNode(nodeToDelete2);
    printList(list2); // 4 5 9

    return 0;
}
