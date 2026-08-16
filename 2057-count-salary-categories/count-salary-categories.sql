# Write your MySQL query statement below

SELECT "Low Salary" AS category, COUNT(*) AS accounts_count FROM Accounts WHERE Accounts.income < 20000
UNION ALL
SELECT "Average Salary" AS category, COUNT(*) AS accounts_count FROM Accounts WHERE Accounts.income BETWEEN 20000 AND 50000
UNION ALL
SELECT "High Salary" AS category, COUNT(*) AS accounts_count FROM Accounts WHERE Accounts.income > 50000;