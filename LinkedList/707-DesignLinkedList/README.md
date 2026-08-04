<div align="center">

# 707. Design Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Custom_Singly_Linked_List-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Design and implement your own linked list (singly or doubly) without using built-in library. Support get, addAtHead, addAtTail, addAtIndex, deleteAtIndex.

---

## Examples

addAtHead(1) → 1
addAtTail(3) → 1->3
addAtIndex(1,2) → 1->2->3
get(1) → 2
deleteAtIndex(1) → 1->3
get(1) → 3


---

## Approach - Custom Singly Linked List

- Apna **Node** class banao jisme `val` aur `next` pointer ho
- `MyLinkedList` class me `head` pointer aur `size` counter maintain karo
- **get(index)**: 0 se index tak traverse karo, uska value return karo
- **addAtHead**: naya node banao, uska next current head ko point kare, head update karo
- **addAtTail**: end tak traverse karo, naya node link karo
- **addAtIndex**: `index-1` tak traverse karo (predecessor node), naya node insert karo beech me
- **deleteAtIndex**: predecessor tak traverse karo, target node ko skip karke link update karo, memory free karo
- Edge cases handle karo: invalid index, empty list, head insertion/deletion

---

## Complexity

| | |
|---|---|
| Time | O(index) for get/add/delete operations |
| Space | O(n) for storing n nodes |

---

## Solution

```cpp
class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        size--;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/design-linked-list/)
