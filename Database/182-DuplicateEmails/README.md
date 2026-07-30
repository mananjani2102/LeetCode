<div align="center">

# 182. Duplicate Emails

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Database-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-GROUP_BY_HAVING-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-SQL-4479A1?style=for-the-badge&logo=mysql&logoColor=white)

</div>

---

## Problem

Given Person table with id and email columns, report all duplicate emails (emails that appear more than once).

---

## Example

| Input (Person) | Output |
|-------|--------|
| (1,a@b.com), (2,c@d.com), (3,a@b.com) | a@b.com |

---

## Approach - GROUP BY HAVING

Person table:
id=1, email=a@b.com
id=2, email=c@d.com
id=3, email=a@b.com

GROUP BY email:
a@b.com → count=2
c@d.com → count=1

HAVING COUNT(email) > 1:
Only a@b.com qualifies (count=2)

Result: a@b.com ✓


- `GROUP BY email` se sabhi rows ko unke email ke basis pe **group** karo
- `HAVING COUNT(email) > 1` se sirf wo groups filter karo jinme **1 se zyada** rows hain (yani duplicate)
- `SELECT email AS Email` se output column ka naam "Email" set karo jaisa expected hai

---

## Complexity

| | |
|---|---|
| Time | O(n log n) due to grouping/sorting |
| Space | O(n) |

---

## Solution

```sql
SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(email) > 1;
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/duplicate-emails/)
