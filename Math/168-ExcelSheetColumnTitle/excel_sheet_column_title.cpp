// LeetCode 168 - Excel Sheet Column Title
// Approach: Base-26 Conversion (1-indexed)
// Time: O(log n) | Space: O(1)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--;
            char ch = 'A' + (columnNumber % 26);
            result += ch;
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.convertToTitle(1) << endl;   // A
    cout << sol.convertToTitle(28) << endl;  // AB
    cout << sol.convertToTitle(701) << endl; // ZY

    return 0;
}
