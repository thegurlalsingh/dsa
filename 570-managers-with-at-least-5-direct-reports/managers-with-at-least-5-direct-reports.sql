# Write your MySQL query statement below

WITH temp2 as (
WITH temp AS ( 
    SELECT managerID, COUNT(*) as c FROM Employee GROUP BY managerID
) SELECT managerID, c from temp where c >= 5
) SELECT name from Employee, temp2 WHERE temp2.managerID = Employee.id;

