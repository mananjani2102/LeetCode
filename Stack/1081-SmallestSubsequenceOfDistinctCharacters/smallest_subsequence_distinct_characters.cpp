// LeetCode 1081 - Smallest Subsequence of Distinct Characters
// Approach: Monotonic Stack + Last Occurrence Tracking
// Time: O(n) | Space: O(1) fixed 26 size

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> last(26);

        for(int i = 0; i < (int)s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> visited(26, false);

        for(int i = 0; i < (int)s.size(); i++)
        {
            char ch = s[i];

            if(visited[ch - 'a'])
                continue;

            while(!st.empty() &&
                  st.top() > ch &&
                  last[st.top() - 'a'] > i)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.smallestSubsequence("bcabc") << endl;    // abc
    cout << sol.smallestSubsequence("cbacdcbc") << endl; // acdb

    return 0;
}
