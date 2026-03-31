// LeetCode 345 - Reverse Vowels of a String
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !vowels.count(s[left]))  left++;
            while (left < right && !vowels.count(s[right])) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};

int main() {
    Solution sol;

    cout << sol.reverseVowels("IceCreAm") << endl;  // AceCreIm
    cout << sol.reverseVowels("leetcode") << endl;   // leotcede

    return 0;
}