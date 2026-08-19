// LeetCode 1171 - Remove Zero Sum Consecutive Nodes from Linked List
// Approach: Prefix Sum + HashMap
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> lastNodeWithSum;
        int prefixSum = 0;

        ListNode* curr = dummy;
        while (curr) {
            prefixSum += curr->val;
            lastNodeWithSum[prefixSum] = curr;
            curr = curr->next;
        }

        prefixSum = 0;
        curr = dummy;
        while (curr) {
            prefixSum += curr->val;
            curr->next = lastNodeWithSum[prefixSum]->next;
            curr = curr->next;
        }

        return dummy->next;
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

    ListNode* l1 = buildList({1, 2, -3, 3, 1});
    printList(sol.removeZeroSumSublists(l1)); // 3 1

    ListNode* l2 = buildList({1, 2, 3, -3, 4});
    printList(sol.removeZeroSumSublists(l2)); // 1 2 4

    ListNode* l3 = buildList({1, 2, 3, -3, -2});
    printList(sol.removeZeroSumSublists(l3)); // 1

    return 0;
}
