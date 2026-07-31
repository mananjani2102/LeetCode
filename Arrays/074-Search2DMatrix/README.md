<div align="center">

# 74. Search a 2D Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Binary_Search_Flattened-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given m x n matrix where each row sorted and first element of row > last element of previous row, search target in O(log(m*n)) time.

---

## Examples

| Input | Output |
|-------|--------|
| matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]], target=3 | true |
| matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]], target=13 | false |

---

## Approach - Binary Search (treat matrix as flattened 1D array)

matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]] target=13
m=3, n=4, total=12

left=0, right=11
mid=5: row=5/4=1, col=5%4=1 → matrix[1][1]=11
11<13 → left=6

left=6, right=11
mid=8: row=8/4=2, col=8%4=0 → matrix[2][0]=23
23>13 → right=7

left=6, right=7
mid=6: row=6/4=1, col=6%4=2 → matrix[1][2]=16
16>13 → right=5

left=6, right=5 → loop ends, target not found → false ✓


- Kyunki matrix ke properties se ye **effectively ek sorted 1D array** jaisa hai (rows continuous hain)
- Matrix ko **flattened index** (`0` se `m*n-1`) treat karo binary search ke liye
- `mid` se actual `row = mid/n`, `col = mid%n` nikalo
- Standard binary search apply karo — O(log(m*n)) time complexity milti hai

---

## Complexity

| | |
|---|---|
| Time | O(log(m × n)) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/search-a-2d-matrix/)
