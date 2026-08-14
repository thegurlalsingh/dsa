# Write your MySQL query statement below

SELECT employee_id FROM Employees AS e WHERE e.salary < 30000 AND (SELECT COUNT(*) FROM Employees AS m WHERE e.manager_id = m.employee_id) = 0 AND e.manager_id IS NOT NULL ORDER BY e.employee_id ASC;