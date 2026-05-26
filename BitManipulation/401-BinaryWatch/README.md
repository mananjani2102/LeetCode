<div align="center">

# 401. Binary Watch

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit_Manipulation-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Brute_Force_Bit_Count-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

A binary watch has 4 LEDs for hours (0-11) and 6 LEDs for minutes (0-59). Given turnedOn LEDs count, return all possible valid times.

---

## Examples

| Input | Output |
|-------|--------|
| 1 | ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"] |
| 9 | [] |

---

## Approach - Brute Force + Bit Count

Sabhi possible hour (0-11) aur minute (0-59) combinations try karo. Har combination ke liye hour aur minute ke binary representation me set bits count karo (popcount). Agar total bits turnedOn ke barabar ho to wo time valid hai, result me add karo.

---

## Complexity

| | |
|---|---|
| Time | O(1) fixed 12*60 iterations |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                int bits = __builtin_popcount(hour) + __builtin_popcount(minute);

                if (bits == turnedOn) {
                    string minStr = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
                    result.push_back(to_string(hour) + ":" + minStr);
                }
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/binary-watch/)
