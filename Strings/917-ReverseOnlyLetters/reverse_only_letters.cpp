// LeetCode 917 - Reverse Only Letters
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalpha(s[left]))  left++;
            while (left < right && !isalpha(s[right])) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};

int main() {
    Solution sol;

    cout << sol.reverseOnlyLetters("ab-cd")                << endl;  // dc-ba
    cout << sol.reverseOnlyLetters("a-bC-dEf-ghIj")        << endl;  // j-Ih-gfE-dCba
    cout << sol.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;  // Qedo1ct-eeLg=ntse-T!

    return 0;
}