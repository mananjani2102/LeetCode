// LeetCode 71 - Simplify Path
// Approach: Stack (using vector as stack)
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr;

        for (int i = 0; i <= (int)path.size(); i++) {
            if (i == (int)path.size() || path[i] == '/') {
                if (curr == "" || curr == ".") {

                }
                else if (curr == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else {
                    st.push_back(curr);
                }
                curr.clear();
            }
            else {
                curr += path[i];
            }
        }

        string ans;
        for (string &dir : st) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};

int main() {
    Solution sol;

    cout << sol.simplifyPath("/home/") << endl;                          // /home
    cout << sol.simplifyPath("/home//foo/") << endl;                     // /home/foo
    cout << sol.simplifyPath("/home/user/Documents/../Pictures") << endl; // /home/user/Pictures
    cout << sol.simplifyPath("/../") << endl;                             // /
    cout << sol.simplifyPath("/.../a/../b/c/../d/./") << endl;            // /.../b/d

    return 0;
}
