// LeetCode 292 - Nim Game
// Approach: Modulo Pattern (Game Theory)
// Time: O(1) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution sol;

    cout << sol.canWinNim(4) << endl; // 0 (false)
    cout << sol.canWinNim(1) << endl; // 1 (true)
    cout << sol.canWinNim(2) << endl; // 1 (true)

    return 0;
}
