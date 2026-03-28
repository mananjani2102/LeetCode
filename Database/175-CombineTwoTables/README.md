<div align="center">

# 175. Combine Two Tables

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Database-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-LEFT_JOIN-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

`Person` aur `Address` do tables hain.  
Har person ka firstName, lastName, city, state return karo.  
Agar address nahi mila to `null` return karo.

---

## Examples

**Person Table**

| personId | lastName | firstName |
|----------|----------|-----------|
| 1        | Wang     | Allen     |
| 2        | Alice    | Bob       |

**Address Table**

| addressId | personId | city          | state      |
|-----------|----------|---------------|------------|
| 1         | 2        | New York City | New York   |
| 2         | 3        | Leetcode      | California |

**Output**

| firstName | lastName | city          | state    |
|-----------|----------|---------------|----------|
| Allen     | Wang     | Null          | Null     |
| Bob       | Alice    | New York City | New York |

---

## Approach — LEFT JOIN Simulation

```
Person   →  [1:Allen Wang] [2:Bob Alice]
Address  →  {2 → "New York City, New York"}
              {3 → "Leetcode, California"}

personId=1 → map mein nahi → city=Null, state=Null
personId=2 → map mein hai  → city="New York City", state="New York"

Result: Allen Wang | Null | Null
        Bob Alice  | New York City | New York ✓
```

- Address rows ko `unordered_map<personId, Address>` mein daalo
- Har Person ke liye map check karo
- Match mila → address use karo, nahi mila → `"Null"` daalo

---

## SQL Solution

```sql
SELECT
    p.firstName,
    p.lastName,
    a.city,
    a.state
FROM Person p
LEFT JOIN Address a
    ON p.personId = a.personId;
```

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(n + m) |

> n = Person rows, m = Address rows

---

## Link

[LeetCode Problem](https://leetcode.com/problems/combine-two-tables/)