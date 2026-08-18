// LeetCode 138 - Copy List with Random Pointer
// Approach: HashMap (Old Node -> New Node Mapping)
// Time: O(n) | Space: O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mapping;

        Node* curr = head;
        while (curr) {
            mapping[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            mapping[curr]->next = mapping[curr->next];
            mapping[curr]->random = mapping[curr->random];
            curr = curr->next;
        }

        return mapping[head];
    }
};

int main() {
    Solution sol;

    // Build list: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Node* copied = sol.copyRandomList(n1);

    Node* curr = copied;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl; // 7 13 11 10 1

    return 0;
}
