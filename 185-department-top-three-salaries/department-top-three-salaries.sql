# Write your MySQL query statement below

WITH temp2 AS (
WITH temp AS
(SELECT Employee.id, Employee.name, Employee.salary, Department.name as departmentName FROM Employee LEFT JOIN Department ON Employee.departmentId = Department.id)
SELECT *, DENSE_RANK() OVER (PARTITION BY temp.departmentName ORDER BY temp.salary DESC) as rn FROM temp)
SELECT temp2.departmentName AS Department, temp2.name AS Employee, temp2.salary AS Salary FROM temp2 WHERE temp2.rn <= 3;




