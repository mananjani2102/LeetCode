<div align="center">

# 196. Delete Duplicate Emails

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Database-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Self_Join_DELETE-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-SQL-4479A1?style=for-the-badge&logo=mysql&logoColor=white)

</div>

---

## Problem

Given Person table, delete all duplicate emails, keeping only the row with smallest id for each unique email.

---

## Example

| Input | Output |
|-------|--------|
| (1,john@x.com),(2,bob@x.com),(3,john@x.com) | (1,john@x.com),(2,bob@x.com) |

---

## Approach - Self Join DELETE

Person: id=1(john), id=2(bob), id=3(john)

Self join on email match, p1.id > p2.id:
p1=(3,john), p2=(1,john) → match! (3>1) → delete p1(id=3)

Remaining: id=1(john), id=2(bob) ✓


- Table ko **khud ke saath JOIN** karo (`p1` aur `p2`) — condition: same email hona chahiye
- `p1.id > p2.id` condition se sirf wo rows match honge jinka **bada id** hai (yani duplicate copies)
- `DELETE p1` se sirf `p1` (bade id wali duplicate rows) delete hoti hain, `p2` (smallest id) bach jata hai
- Har duplicate group me sirf smallest id wala row bachega

---

## Complexity

| | |
|---|---|
| Time | O(n²) due to self join |
| Space | O(n) |

---

## Solution

```sql
DELETE p1
FROM Person p1
JOIN Person p2
ON p1.email = p2.email AND p1.id > p2.id;
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/delete-duplicate-emails/)
