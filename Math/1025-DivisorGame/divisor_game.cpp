// LeetCode 1025 - Divisor Game
// Approach: Parity Pattern (Game Theory)
// Time: O(1) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};

int main() {
    Solution sol;

    cout << sol.divisorGame(2) << endl; // 1 (true)
    cout << sol.divisorGame(3) << endl; // 0 (false)

    return 0;
}
