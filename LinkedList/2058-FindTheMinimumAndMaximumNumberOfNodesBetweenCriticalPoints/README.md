<div align="center">

# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked_List-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Single_Pass_Traversal-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a linked list, find all critical points (local maxima/minima, needs both prev and next node). Return `[minDistance, maxDistance]` between any two distinct critical points, or `[-1,-1]` if fewer than 2 exist.

---

## Examples

| Input | Output |
|-------|--------|
| [3,1] | [-1,-1] |
| [5,3,1,2,5,1,2] | [1,3] |
| [1,3,2,2,3,2,2,2,7] | [3,3] |

---

## Approach - Single Pass Traversal
head = [5,3,1,2,5,1,2]
prev=5(idx0), curr=3(idx1), firstIdx=-1, prevIdx=-1, minDist=INF

idx=1,curr=3: isMax?(3>5? no) isMin?(3<5 && 3<1? no) → not critical
  prev=3, curr=1, idx=2

idx=2,curr=1: isMax?(1>3? no) isMin?(1<3 && 1<2? yes) → critical!
  firstIdx==-1 → firstIdx=2, prevIdx=2
  prev=1, curr=2, idx=3

idx=3,curr=2: isMax?(2>1 && 2>5? no) isMin?(2<1? no) → not critical
  prev=2, curr=5, idx=4

idx=4,curr=5: isMax?(5>2 && 5>1? yes) → critical!
  firstIdx!=-1 → minDist=min(INF, 4-2)=2, prevIdx=4
  prev=5, curr=1, idx=5

idx=5,curr=1: isMax?(1>5? no) isMin?(1<5 && 1<2? yes) → critical!
  minDist=min(2, 5-4)=1, prevIdx=5
  prev=1, curr=2, idx=6
  curr->next is null → loop ends

firstIdx=2, prevIdx=5 → maxDist = 5-2 = 3
Result = [1,3] ✓


- List ko `prev`, `curr` pointers se traverse karo shuru se (`prev=head`, `curr=head->next`), aur ek `idx` counter rakho jo `curr` ka position track kare (index 1 se start)
- Har `curr` node ke liye check karo ki wo **local maxima** hai (`curr->val > prev->val && curr->val > curr->next->val`) ya **local minima** — dono checks ke liye `curr->next` hona zaroori hai isliye loop `while(curr->next)` tak chalta hai
- Jab pehla critical point mile, uska index `firstIdx` me save karo (maxDistance calculate karne ke liye baad me chahiye hoga)
- Har agle critical point pe, `minDist` ko **current aur pichle critical point ke beech ki distance** se update karo (`idx - prevIdx`), aur `prevIdx` ko update kar do
- Loop khatam hone ke baad, agar **2 se kam critical points** mile (`firstIdx==-1` ya sirf ek hi mila) to `{-1,-1}` return karo — warna `maxDist = prevIdx - firstIdx` (pehle aur aakhri critical point ke beech ki distance, jo hamesha maximum hoti hai kyunki beech ke saare critical points ispe hi lagte hai) aur pehle se track kiya hua `minDist` return karo
- Ek hi pass me dono answers mil jaate hai, kisi extra array me saare critical points store karne ki zarurat nahi

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, prevIdx = -1, minDist = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        while (curr->next) {
            bool isMax = curr->val > prev->val && curr->val > curr->next->val;
            bool isMin = curr->val < prev->val && curr->val < curr->next->val;

            if (isMax || isMin) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - prevIdx);
                }
                prevIdx = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (firstIdx == -1 || firstIdx == prevIdx) return {-1, -1};

        int maxDist = prevIdx - firstIdx;
        return {minDist, maxDist};
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)
