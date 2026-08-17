# Write your MySQL query statement below

SELECT Activities.sell_date, COUNT(DISTINCT Activities.product) as num_sold, GROUP_CONCAT(DISTINCT Activities.product ORDER BY Activities.product SEPARATOR ',') AS products FROM Activities GROUP BY Activities.sell_date;