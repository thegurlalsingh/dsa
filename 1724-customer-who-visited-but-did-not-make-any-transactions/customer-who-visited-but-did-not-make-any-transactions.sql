# Write your MySQL query statement below

WITH temp AS (
    SELECT customer_id FROM Visits LEFT JOIN Transactions ON Transactions.visit_id = Visits.visit_id WHERE Transactions.transaction_id IS NULL
)
SELECT customer_id , COUNT(*) AS count_no_trans
FROM temp GROUP BY customer_id;




-- SELECT customer_id, COUNT(*) from temp GROUP BY visit_id;