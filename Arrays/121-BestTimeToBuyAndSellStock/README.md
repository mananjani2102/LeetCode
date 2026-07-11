<div align="center">

# 121. Best Time to Buy and Sell Stock

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Track_Min_Price-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given prices array where prices[i] is stock price on day i, find max profit by buying once and selling once later. Return 0 if no profit possible.

---

## Examples

| Input | Output |
|-------|--------|
| [7,1,5,3,6,4] | 5 |
| [7,6,4,3,1] | 0 |

---

## Approach - Track Min Price + Max Profit
prices = [7,1,5,3,6,4]
minPrice=7
i=1: 1<7 → minPrice=1
i=2: 5>=1 → profit=5-1=4, maxProfit=4
i=3: 3>=1 → profit=3-1=2, maxProfit=4
i=4: 6>=1 → profit=6-1=5, maxProfit=5
i=5: 4>=1 → profit=4-1=3, maxProfit=5
Answer = 5 ✓

- `minPrice` track karo — ab tak ka **sabse chota** price
- Har din ke liye check karo: agar aaj ka price `minPrice` se chota hai to `minPrice` update karo
- Warna aaj bech kar profit calculate karo (`price - minPrice`) aur `maxProfit` update karo
- Single pass me hi answer mil jata hai

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
