// LeetCode 394 - Decode String
// Approach: Two Stacks (Number Stack + String Stack)
// Time: O(n) | Space: O(n)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }
            else if (ch == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            }
            else if (ch == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string prevStr = strStack.top();
                strStack.pop();
                string temp = "";
                for (int i = 0; i < repeat; i++) {
                    temp += currStr;
                }
                currStr = prevStr + temp;
            }
            else {
                currStr += ch;
            }
        }
        return currStr;
    }
};

int main() {
    Solution sol;

    cout << sol.decodeString("3[a]2[bc]") << endl;     // aaabcbc
    cout << sol.decodeString("3[a2[c]]") << endl;       // accaccacc
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;  // abcabccdcdcdef

    return 0;
}
