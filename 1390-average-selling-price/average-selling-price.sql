# Write your MySQL query statement below

WITH temp2 as (WITH temp as
(SELECT Prices.product_id, Prices.price, Prices.start_date, Prices.end_date, UnitsSold.purchase_date, UnitsSold.units FROM Prices LEFT JOIN UnitsSold ON Prices.product_id = UnitsSold.product_id AND UnitsSold.purchase_date BETWEEN Prices.start_date AND Prices.end_date)
SELECT temp.product_id, ROUND(SUM(temp.units * temp.price) / SUM(units), 2) as average_price FROM temp GROUP BY temp.product_id) SELECT temp2.product_id, CASE WHEN temp2.average_price IS NOT NULL THEN temp2.average_price ELSE 0 END AS average_price FROM temp2;