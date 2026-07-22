<div align="center">

# 3499. Maximize Active Section with Trade I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Block_Compression_Greedy-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given binary string s, perform at most one trade (flip a 0-block surrounded by 1s to 1s, after converting a surrounded 1-block to 0s) to maximize active ('1') sections. String is augmented with '1' at both ends.

---

## Examples

| Input | Output |
|-------|--------|
| "01" | 1 |
| "0100" | 4 |
| "1000100" | 7 |
| "01010" | 4 |

---

## Approach - Block Compression Greedy

s = "0100" augmented t = "101001"

Blocks: '1'(1), '0'(1), '1'(1), '0'(2), '1'(1)
indices: 0='1'(1), 1='0'(1), 2='1'(1), 3='0'(2), 4='1'(1)

Check middle blocks (i=1 to 3):
i=1: block='0', not '1' → skip
i=2: block='1', left='0'(len1), right='0'(len2) → gain=1+2=3
i=3: block='0', not '1' → skip

maxGain=3
ones (in original s) = 1
Answer = 1+3 = 4 ✓


- Pehle original string me `1`s ka count nikalo
- String ko **augment** karo `1` se dono end pe (jaise `t = "1"+s+"1"`)
- **Run-length encoding** se blocks banao — har block ka character aur length
- Har `1`-block (jo dono taraf `0`-blocks se ghira ho) ke liye, **trade gain** calculate karo: dono adjacent `0`-blocks ki length ka sum (kyunki wo `1`-block ko convert karke ye dono 0-blocks ko 1 me convert kar sakte ho)
- Maximum gain dhundo aur original ones count me add karo

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
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for (char ch : s) {
            if (ch == '1')
                ones++;
        }

        string t = "1" + s + "1";

        vector<char> blockChar;
        vector<int> blockLen;

        int i = 0;

        while (i < t.size()) {
            char ch = t[i];
            int len = 0;

            while (i < t.size() && t[i] == ch) {
                len++;
                i++;
            }

            blockChar.push_back(ch);
            blockLen.push_back(len);
        }

        int maxGain = 0;

        for (int i = 1; i + 1 < blockChar.size(); i++) {

            if (blockChar[i] == '1' &&
                blockChar[i - 1] == '0' &&
                blockChar[i + 1] == '0') {

                int gain = blockLen[i - 1] + blockLen[i + 1];
                maxGain = max(maxGain, gain);
            }
        }

        return ones + maxGain;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/maximize-active-section-with-trade-i/)
