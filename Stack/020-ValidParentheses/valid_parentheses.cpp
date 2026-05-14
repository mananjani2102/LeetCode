// LeetCode 20 - Valid Parentheses
// Approach: Stack
// Time: O(n) | Space: O(n)

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty()) return false;

                char top = st.top();

                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    cout << sol.isValid("()") << endl;      // 1 (true)
    cout << sol.isValid("()[]{}") << endl;   // 1 (true)
    cout << sol.isValid("(]") << endl;       // 0 (false)
    cout << sol.isValid("([])") << endl;     // 1 (true)
    cout << sol.isValid("([)]") << endl;     // 0 (false)

    return 0;
}