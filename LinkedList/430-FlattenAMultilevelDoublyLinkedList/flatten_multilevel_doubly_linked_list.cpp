// LeetCode 430 - Flatten a Multilevel Doubly Linked List
// Approach: Recursive DFS
// Time: O(n) | Space: O(d) where d = max depth of nesting

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = curr->child;

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                Node* childTail = childHead;
                while (childTail->next) {
                    childTail = childTail->next;
                }

                childTail->next = nextNode;
                if (nextNode) {
                    nextNode->prev = childTail;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};

int main() {
    Solution sol;

    // Build example 2: [1,2,null,3] → 1<->2, 2.child=3
    Node* n3 = new Node(3);
    Node* n2 = new Node(2);
    Node* n1 = new Node(1);
    n1->next = n2; n2->prev = n1;
    n2->child = n3;

    Node* result = sol.flatten(n1);

    Node* curr = result;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl; // 1 3 2

    return 0;
}
