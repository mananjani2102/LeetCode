// LeetCode 2074 - Reverse Nodes in Even Length Groups
// Approach: In-place Group Reversal
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prevGroupEnd = head;
        int groupNumber = 1;
        ListNode* curr = head->next;

        while (curr) {
            groupNumber++;
            int groupLen = groupNumber;

            ListNode* node = curr;
            int count = 1;
            while (count < groupLen && node->next) {
                node = node->next;
                count++;
            }

            ListNode* nextGroupStart = node->next;

            if (count % 2 == 0) {
                ListNode* prev = nextGroupStart;
                ListNode* cur2 = curr;
                for (int i = 0; i < count; i++) {
                    ListNode* nxt = cur2->next;
                    cur2->next = prev;
                    prev = cur2;
                    cur2 = nxt;
                }
                prevGroupEnd->next = node;
                prevGroupEnd = curr;
            } else {
                prevGroupEnd = node;
            }

            curr = nextGroupStart;
        }

        return head;
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

    ListNode* l1 = buildList({5, 2, 6, 3, 9, 1, 7, 3, 8, 4});
    printList(sol.reverseEvenLengthGroups(l1)); // 5 6 2 3 9 1 4 8 3 7

    ListNode* l2 = buildList({1, 1, 0, 6});
    printList(sol.reverseEvenLengthGroups(l2)); // 1 0 1 6

    ListNode* l3 = buildList({1, 1, 0, 6, 5});
    printList(sol.reverseEvenLengthGroups(l3)); // 1 0 1 5 6

    return 0;
}
