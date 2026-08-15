# Write your MySQL query statement below

WITH temp AS
(SELECT e1.employee_id, e1.age, e1.reports_to, e2.name FROM Employees AS e1 LEFT JOIN Employees AS e2 ON e1.reports_to = e2.employee_id WHERE e1.reports_to IS NOT NULL)
SELECT temp.reports_to AS employee_id, temp.name, COUNT(*) as reports_count, ROUND(AVG(temp.age)) AS average_age FROM temp GROUP BY temp.reports_to ORDER BY temp.reports_to ASC;