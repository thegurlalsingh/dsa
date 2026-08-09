# Write your MySQL query statement below
WITH temp as
(SELECT Project.project_id, Employee.employee_id, Employee.experience_years FROM Project LEFT JOIN Employee ON Project.employee_id = Employee.employee_id)
SELECT temp.project_id, ROUND(AVG(temp.experience_years), 2) AS average_years FROM temp GROUP BY temp.project_id;


