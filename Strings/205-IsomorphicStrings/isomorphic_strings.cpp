// LeetCode 205 - Isomorphic Strings
// Approach: Two HashMaps for Bidirectional Mapping
// Time: O(n) | Space: O(1) fixed alphabet size

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < (int)s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapST.count(c1) && mapST[c1] != c2) return false;
            if (mapTS.count(c2) && mapTS[c2] != c1) return false;

            mapST[c1] = c2;
            mapTS[c2] = c1;
        }

        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isIsomorphic("egg", "add") << endl;   // 1 (true)
    cout << sol.isIsomorphic("f11", "b23") << endl;    // 0 (false)
    cout << sol.isIsomorphic("paper", "title") << endl; // 1 (true)

    return 0;
}
