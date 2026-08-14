# Write your MySQL query statement below
WITH temp as
(SELECT Sales.product_id, Sales.year, Sales.quantity, Sales.price, RANK() OVER(PARTITION BY Sales.product_id ORDER BY Sales.year) as rn FROM Sales)
SELECT temp.product_id, temp.year as first_year, temp.quantity, temp.price FROM temp WHERE temp.rn = 1;