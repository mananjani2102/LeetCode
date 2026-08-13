// LeetCode 1019 - Next Greater Node In Linked List
// Approach: Monotonic Stack (Convert to Array First)
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        int n = values.size();
        vector<int> result(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && values[st.top()] < values[i]) {
                result[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
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

    ListNode* list1 = buildList({2, 1, 5});
    vector<int> r1 = sol.nextLargerNodes(list1);
    for (int x : r1) cout << x << " ";
    cout << endl; // 5 5 0

    ListNode* list2 = buildList({2, 7, 4, 3, 5});
    vector<int> r2 = sol.nextLargerNodes(list2);
    for (int x : r2) cout << x << " ";
    cout << endl; // 7 0 5 5 0

    return 0;
}
