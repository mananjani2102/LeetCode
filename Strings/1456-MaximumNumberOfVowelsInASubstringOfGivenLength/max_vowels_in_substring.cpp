// LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length
// Approach: Sliding Window
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        int ans = count;  

        for (int i = k; i < (int)s.size(); i++) {

            if (isVowel(s[i - k])) {
                count--;
            }

            if (isVowel(s[i])) {
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.maxVowels("abciiidef", 3) << endl; // 3
    cout << sol.maxVowels("aeiou", 2) << endl;      // 2
    cout << sol.maxVowels("leetcode", 3) << endl;   // 2

    return 0;
}
