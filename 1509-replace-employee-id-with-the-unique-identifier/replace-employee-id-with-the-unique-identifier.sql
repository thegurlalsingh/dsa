# Write your MySQL query statement below

# Keep everything from employees table, so performing right join on employees table because on right side we have employees table content

SELECT EmployeeUNI.unique_id, Employees.name FROM EmployeeUNI RIGHT JOIN Employees on EmployeeUNI.id = Employees.id;