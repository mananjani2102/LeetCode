-- LeetCode 182 - Duplicate Emails
-- Approach: GROUP BY + HAVING
-- Time Complexity: O(n log n) due to grouping
-- Space Complexity: O(n)

SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(email) > 1;
