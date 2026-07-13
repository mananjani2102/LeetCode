// LeetCode 12 - Integer to Roman
// Approach: Greedy with Value-Symbol Pairs
// Time: O(1) fixed 13 symbols max | Space: O(1)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";

        for (auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                result += symbol;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.intToRoman(3749) << endl; // MMMDCCXLIX
    cout << sol.intToRoman(58) << endl;   // LVIII
    cout << sol.intToRoman(1994) << endl; // MCMXCIV

    return 0;
}
