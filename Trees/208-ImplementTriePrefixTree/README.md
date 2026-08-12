<div align="center">

# 208. Implement Trie (Prefix Tree)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Trees-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Array_Based_Trie-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Implement Trie class with insert(word), search(word), and startsWith(prefix) methods.

---

## Examples

insert("apple")
search("apple") → true
search("app") → false
startsWith("app") → true
insert("app")
search("app") → true


---

## Approach - Array Based Trie

insert("app"):
root -> 'a' -> 'p' -> 'p'(isEnd=true)

search("app"):
Traverse root->a->p->p, check isEnd=true → found! true

startsWith("ap"):
Traverse root->a->p, path exists (no isEnd check needed) → true


- Har Trie node me **26 children pointers** (a-z ke liye) aur ek `isEnd` flag hota hai
- **insert**: character by character traverse karo, agar path exist nahi karta to naya node banao, end me `isEnd=true` set karo
- **search**: character by character traverse karo, agar path na mile to `false`, path mile to `isEnd` check karo (poora word match hona chahiye)
- **startsWith**: sirf path exist karna chahiye, `isEnd` check karne ki zaroorat nahi
- Ye data structure **prefix-based** operations me bahut efficient hai (autocomplete, spellcheck jaisi applications)

---

## Complexity

| | |
|---|---|
| Time | O(m) per operation, m = word/prefix length |
| Space | O(total characters inserted) |

---

## Solution

```cpp
class Trie {
public:
    Trie* children[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/implement-trie-prefix-tree/)
