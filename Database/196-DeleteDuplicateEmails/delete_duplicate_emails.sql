-- LeetCode 196 - Delete Duplicate Emails
-- Approach: Self Join + DELETE
-- Time Complexity: O(n^2) due to self join
-- Space Complexity: O(n)

DELETE p1
FROM Person p1
JOIN Person p2
ON p1.email = p2.email AND p1.id > p2.id;
