// LeetCode 2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points
// Approach: Single Pass Traversal
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, prevIdx = -1, minDist = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        while (curr->next) {
            bool isMax = curr->val > prev->val && curr->val > curr->next->val;
            bool isMin = curr->val < prev->val && curr->val < curr->next->val;

            if (isMax || isMin) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - prevIdx);
                }
                prevIdx = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (firstIdx == -1 || firstIdx == prevIdx) return {-1, -1};

        int maxDist = prevIdx - firstIdx;
        return {minDist, maxDist};
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

int main() {
    Solution sol;

    ListNode* l1 = buildList({3, 1});
    auto r1 = sol.nodesBetweenCriticalPoints(l1);
    cout << r1[0] << " " << r1[1] << endl; // -1 -1

    ListNode* l2 = buildList({5, 3, 1, 2, 5, 1, 2});
    auto r2 = sol.nodesBetweenCriticalPoints(l2);
    cout << r2[0] << " " << r2[1] << endl; // 1 3

    ListNode* l3 = buildList({1, 3, 2, 2, 3, 2, 2, 2, 7});
    auto r3 = sol.nodesBetweenCriticalPoints(l3);
    cout << r3[0] << " " << r3[1] << endl; // 3 3

    return 0;
}
