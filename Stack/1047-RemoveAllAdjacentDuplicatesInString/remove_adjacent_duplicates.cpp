// LeetCode 1047 - Remove All Adjacent Duplicates In String
// Approach: Stack
// Time: O(n) | Space: O(n)

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && st.top() == ch) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.removeDuplicates("abbaca") << endl; // ca
    cout << sol.removeDuplicates("azxxzy") << endl;  // ay

    return 0;
}
