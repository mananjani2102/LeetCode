<div align="center">

# 2626. Array Reduce Transformation

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-JavaScript-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Manual_Loop-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)

</div>

---

## Problem

Given array nums, reducer function fn, and initial value init, implement reduce functionality manually without using built-in Array.reduce.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[1,2,3,4], fn=sum, init=0 | 10 |
| nums=[1,2,3,4], fn=sum+square, init=100 | 130 |
| nums=[], fn=anything, init=25 | 25 |

---

## Approach - Manual Loop (without built-in Array.reduce)

nums = [1,2,3,4] fn = (accum,curr) => accum+curr init=0

val=0
i=0: val=fn(0,1)=1
i=1: val=fn(1,2)=3
i=2: val=fn(3,3)=6
i=3: val=fn(6,4)=10

Return val=10 ✓


- `val` variable ko `init` se start karo
- Har element `nums[i]` ke liye, `fn` function ko current `val` aur `nums[i]` pass karke call karo, result wapas `val` me store karo
- Loop khatam hone ke baad `val` hi final answer hai
- Agar array **empty** hai to loop bilkul chalega hi nahi, `val` (jo `init` hai) wapas return ho jayega

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```javascript
var reduce = function(nums, fn, init) {
    let val = init;

    for (let i = 0; i < nums.length; i++) {
        val = fn(val, nums[i]);
    }

    return val;
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/array-reduce-transformation/)
