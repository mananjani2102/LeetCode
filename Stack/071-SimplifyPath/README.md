<div align="center">

# 71. Simplify Path

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an absolute Unix-style path, transform it into its simplified canonical path - handle single dots, double dots, multiple slashes, and trailing slashes.

---

## Examples

| Input | Output |
|-------|--------|
| "/home/" | "/home" |
| "/home//foo/" | "/home/foo" |
| "/home/user/Documents/../Pictures" | "/home/user/Pictures" |
| "/../" | "/" |
| "/.../a/../b/c/../d/./" | "/.../b/d" |

---

## Approach - Stack (using vector as stack)

Path ko character by character traverse karo, jab '/' ya end of string mile to current accumulated string (curr) ko process karo. Agar curr empty hai ya "." hai to ignore karo. Agar ".." hai to stack se ek directory pop karo (parent ke upar jana). Warna curr ko valid directory naam maan kar stack me push karo. End me stack ke sabhi elements ko "/" se jod kar final path banao.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
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
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/simplify-path/)
