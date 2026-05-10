// LeetCode 8 - String to Integer (atoi)
// Approach: Manual Parsing
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long result = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign * result);
    }
};

int main() {
    Solution sol;

    cout << sol.myAtoi("42") << endl;              // 42
    cout << sol.myAtoi("   -042") << endl;          // -42
    cout << sol.myAtoi("1337c0d3") << endl;         // 1337
    cout << sol.myAtoi("0-1") << endl;              // 0
    cout << sol.myAtoi("words and 987") << endl;    // 0

    return 0;
}