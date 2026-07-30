// LeetCode 3014 - Minimum Number of Pushes to Type Word I
// Approach: Greedy Distribution (8 keys, distinct letters)
// Time: O(1) since word.length <= 26 | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int totalPushes = 0;

        for (int i = 0; i < n; i++) {
            int pushCount = (i / 8) + 1;
            totalPushes += pushCount;
        }

        return totalPushes;
    }
};

int main() {
    Solution sol;

    cout << sol.minimumPushes("abcde") << endl;        // 5
    cout << sol.minimumPushes("xycdefghij") << endl;   // 12

    return 0;
}
