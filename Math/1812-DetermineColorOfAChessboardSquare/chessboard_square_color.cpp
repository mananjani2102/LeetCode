// LeetCode 1812 - Determine Color of a Chessboard Square
// Approach: Parity Check (column + row)
// Time: O(1) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a') - (coordinates[1] - '1')) % 2;
    }
};

int main() {
    Solution sol;

    cout << sol.squareIsWhite("a1") << endl; // 0 (false)
    cout << sol.squareIsWhite("h3") << endl; // 1 (true)
    cout << sol.squareIsWhite("c7") << endl; // 0 (false)

    return 0;
}
