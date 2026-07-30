<div align="center">

# 183. Customers Who Never Order

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Database-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-LEFT_JOIN_NULL_Check-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-SQL-4479A1?style=for-the-badge&logo=mysql&logoColor=white)

</div>

---

## Problem

Given Customers and Orders tables, find all customers who never placed any order.

---

## Example

| Input | Output |
|-------|--------|
| Customers: Joe, Henry, Sam, Max; Orders: customerId 3, 1 | Henry, Max |

---

## Approach - LEFT JOIN NULL Check

Customers: id=1(Joe), id=2(Henry), id=3(Sam), id=4(Max)
Orders: customerId=3, customerId=1

LEFT JOIN Customers with Orders on id=customerId:
Joe(1) → matched with order → o.customerId=1
Henry(2) → no match → o.customerId=NULL
Sam(3) → matched with order → o.customerId=3
Max(4) → no match → o.customerId=NULL

WHERE o.customerId IS NULL:
Henry, Max ✓


- `LEFT JOIN` se **Customers** table ke saare rows preserve honge, chahe unka `Orders` me match ho ya nahi
- Agar customer ne koi order nahi diya, to joined row me `Orders` ki columns **NULL** honge
- `WHERE o.customerId IS NULL` se sirf wo customers filter karo jinka koi matching order nahi mila
- `AS Customers` se output column ka naam expected format me set karo

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(n) |

---

## Solution

```sql
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerId
WHERE o.customerId IS NULL;
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/customers-who-never-order/)
