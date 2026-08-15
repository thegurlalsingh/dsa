# Write your MySQL query statement below


SELECT Seat.id, CASE WHEN Seat.id % 2 = 1 AND Seat.id < (SELECT MAX(Seat.id) FROM Seat) THEN LEAD(Seat.student) OVER (ORDER BY Seat.id) WHEN id % 2 = 0 THEN LAG(Seat.student) OVER (ORDER BY Seat.id) ELSE Seat.student END AS student FROM Seat ORDER BY Seat.id;