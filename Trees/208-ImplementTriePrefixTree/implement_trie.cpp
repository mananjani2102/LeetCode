// LeetCode 208 - Implement Trie (Prefix Tree)
// Approach: Array-based Trie Node (26 children)
// Time: O(m) per operation where m = word length | Space: O(total characters)

#include <iostream>
#include <string>
using namespace std;

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

int main() {
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;    // 1 (true)
    cout << trie.search("app") << endl;      // 0 (false)
    cout << trie.startsWith("app") << endl;  // 1 (true)
    trie.insert("app");
    cout << trie.search("app") << endl;      // 1 (true)

    return 0;
}
