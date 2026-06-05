// LeetCode 1209 - Remove All Adjacent Duplicates in String II
// Approach: Two Pointer + Count Array (Stack Simulation)
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        vector<int> cnt(n);

        int j = 0;

        for (int i = 0; i < n; ++i, ++j) {
            s[j] = s[i];

            cnt[j] = (j > 0 && s[j] == s[j - 1])
                     ? cnt[j - 1] + 1
                     : 1;

            if (cnt[j] == k)
                j -= k;
        }

        return s.substr(0, j);
    }
};

int main() {
    Solution sol;

    cout << sol.removeDuplicates("abcd", 2) << endl;                  // abcd
    cout << sol.removeDuplicates("deeedbbcccbdaa", 3) << endl;        // aa
    cout << sol.removeDuplicates("pbbcggttciiippooaais", 2) << endl;  // ps

    return 0;
}
