// LeetCode 1784 - Check if Binary String Has at Most One Segment of Ones
// Approach: Count Segment Starts
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;

        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) {
                count++;
            }
        }

        if (count <= 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution sol;

    cout << sol.checkOnesSegment("1001") << endl; // 0 (false)
    cout << sol.checkOnesSegment("110") << endl;  // 1 (true)

    return 0;
}
