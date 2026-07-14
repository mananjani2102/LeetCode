// LeetCode 242 - Valid Anagram
// Approach: Frequency Array
// Time: O(n) | Space: O(1) fixed 26 size

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (char ch : t) {
            freq[ch - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isAnagram("anagram", "nagaram") << endl; // 1 (true)
    cout << sol.isAnagram("rat", "car") << endl;          // 0 (false)

    return 0;
}
