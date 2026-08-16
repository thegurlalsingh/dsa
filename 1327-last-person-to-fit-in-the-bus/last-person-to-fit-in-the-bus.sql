# Write your MySQL query statement below

WITH temp2 AS
(WITH temp AS
(SELECT *, SUM(Queue.weight) OVER (ORDER BY Queue.turn) AS total_wt FROM Queue ORDER BY(Queue.turn) ASC)
SELECT * FROM temp WHERE temp.total_wt <= 1000)
SELECT temp2.person_name FROM temp2 ORDER BY (temp2.turn) DESC LIMIT 1;