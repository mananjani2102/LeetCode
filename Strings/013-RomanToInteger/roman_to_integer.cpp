// LeetCode 13 - Roman to Integer
// Approach: HashMap + Subtraction Check
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int n = (int)s.size();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && values[s[i]] < values[s[i + 1]]) {
                total -= values[s[i]];
            } else {
                total += values[s[i]];
            }
        }

        return total;
    }
};

int main() {
    Solution sol;

    cout << sol.romanToInt("III") << endl;       // 3
    cout << sol.romanToInt("LVIII") << endl;      // 58
    cout << sol.romanToInt("MCMXCIV") << endl;    // 1994

    return 0;
}