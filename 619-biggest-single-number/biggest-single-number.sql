# Write your MySQL query statement below
WITH temp AS
(SELECT MyNumbers.num, COUNT(*) as count FROM MyNumbers GROUP BY(MyNumbers.num) ORDER BY num DESC)
SELECT (SELECT temp.num FROM temp WHERE temp.count = 1 LIMIT 1) AS num; 

-- wrap it around one more table so that if ans is no row it can return null