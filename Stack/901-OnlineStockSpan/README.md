<div align="center">

# 901. Online Stock Span

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Monotonic_Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Design StockSpanner class that returns the span of stock price - the number of consecutive days (going backward from today) where price was less than or equal to today's price.

---

## Examples

| Calls | Output |
|-------|--------|
| next(100), next(80), next(60), next(70), next(60), next(75), next(85) | 1, 1, 1, 2, 1, 4, 6 |

---

## Approach - Monotonic Stack (price, span pairs)

Stack me (price, span) pairs store karo. Naya price aane par, stack ke top wale prices jo current price se chote ya equal hain unko pop karo aur unke spans current span me add karo. Fir current (price, span) ko push kar do. Ye stack monotonically decreasing prices maintain karta hai, isliye amortized O(1) time lagta hai.

---

## Complexity

| | |
|---|---|
| Time | O(1) amortized per call |
| Space | O(n) |

---

## Solution

```cpp
class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {   
    }
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/online-stock-span/)
