# Write your MySQL query statement below
WITH temp AS
(SELECT Employee.name, Bonus.bonus FROM Employee LEFT JOIN Bonus ON Employee.empId = Bonus.empId)
SELECT name, bonus FROM temp WHERE temp.bonus < 1000 OR temp.bonus IS NULL;


-- '*' does not work under this nested table