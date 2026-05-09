// LeetCode 6 - Zigzag Conversion
// Approach: Simulate Rows
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string result = "";
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.convert("PAYPALISHIRING", 3) << endl; // "PAHNAPLSIIGYIR"
    cout << sol.convert("PAYPALISHIRING", 4) << endl; // "PINALSIGYAHRPI"
    cout << sol.convert("A", 1) << endl;               // "A"

    return 0;
}