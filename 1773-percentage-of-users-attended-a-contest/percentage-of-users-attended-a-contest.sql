# Write your MySQL query statement below
WITH temp AS
(SELECT Register.contest_id, COUNT(DISTINCT user_id) as total_contest FROM Register GROUP BY Register.contest_id)
SELECT temp.contest_id, ROUND(temp.total_contest * 100.0 / (SELECT COUNT(*) FROM Users),2) as percentage FROM temp ORDER BY percentage DESC, contest_id ASC;