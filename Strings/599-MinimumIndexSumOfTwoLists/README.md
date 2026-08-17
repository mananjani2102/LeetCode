<div align="center">

# 599. Minimum Index Sum of Two Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashMap_Index_Tracking-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two string arrays list1 and list2, find common strings with the minimum index sum (i+j where string is at list1[i] and list2[j]).

---

## Examples

| Input | Output |
|-------|--------|
| list1=["Shogun","Tapioca Express","Burger King","KFC"], list2=["Piatti",...,"Shogun"] | ["Shogun"] |
| list1=["happy","sad","good"], list2=["sad","happy","good"] | ["sad","happy"] |

---

## Approach - HashMap Index Tracking

list1 = ["happy","sad","good"] list2 = ["sad","happy","good"]

indexMap (from list1): happy:0, sad:1, good:2

Check list2:
j=0,"sad": found in map(idx=1) → sum=1+0=1 → minSum=1, result=["sad"]
j=1,"happy": found(idx=0) → sum=0+1=1 → equal to minSum → result=["sad","happy"]
j=2,"good": found(idx=2) → sum=2+2=4 → greater, skip

Result = ["sad","happy"] ✓


- `list1` ke har string ka **index** HashMap me store karo
- `list2` traverse karo — agar string `list1` me bhi hai, to **index sum** calculate karo (`indexMap[string] + j`)
- Agar naya sum **chota** hai to result reset karo aur naya string add karo
- Agar sum **equal** hai to result me bhi add karo (multiple answers ho sakte hain)

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;

        for (int i = 0; i < list1.size(); i++) {
            indexMap[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for (int j = 0; j < list2.size(); j++) {
            if (indexMap.count(list2[j])) {
                int sum = indexMap[list2[j]] + j;

                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                }
                else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)
