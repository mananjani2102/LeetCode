-- LeetCode 183 - Customers Who Never Order
-- Approach: LEFT JOIN + WHERE NULL check
-- Time Complexity: O(n+m)
-- Space Complexity: O(n)

SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerId
WHERE o.customerId IS NULL;
