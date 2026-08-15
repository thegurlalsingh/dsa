# Write your MySQL query statement below

WITH temp AS
(SELECT Employee.employee_id, CASE WHEN (SELECT COUNT(*) FROM Employee AS e WHERE e.employee_id = Employee.employee_id) = 1 THEN department_id WHEN (SELECT COUNT(*) FROM Employee AS e WHERE e.employee_id = Employee.employee_id) > 1 AND Employee.primary_flag = "Y" THEN department_id END AS department_id FROM Employee)
SELECT * FROM temp WHERE temp.department_id IS NOT NULL;