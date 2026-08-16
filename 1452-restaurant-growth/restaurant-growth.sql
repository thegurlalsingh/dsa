WITH temp AS
(SELECT
    c1.visited_on,

    CASE
        WHEN (
            SELECT COUNT(DISTINCT c2.visited_on)
            FROM Customer AS c2
            WHERE c2.visited_on BETWEEN
                  DATE_SUB(c1.visited_on, INTERVAL 6 DAY)
                  AND c1.visited_on
        ) = 7

        THEN (
            SELECT SUM(c3.amount)
            FROM Customer AS c3
            WHERE c3.visited_on BETWEEN
                  DATE_SUB(c1.visited_on, INTERVAL 6 DAY)
                  AND c1.visited_on
        )
    END AS amount,

    CASE
        WHEN (
            SELECT COUNT(DISTINCT c4.visited_on)
            FROM Customer AS c4
            WHERE c4.visited_on BETWEEN
                  DATE_SUB(c1.visited_on, INTERVAL 6 DAY)
                  AND c1.visited_on
        ) = 7

        THEN ROUND(
            (
                SELECT SUM(c5.amount)
                FROM Customer AS c5
                WHERE c5.visited_on BETWEEN
                      DATE_SUB(c1.visited_on, INTERVAL 6 DAY)
                      AND c1.visited_on
            ) / 7,
            2
        )
    END AS average_amount

FROM Customer AS c1)
SELECT DISTINCT * FROM temp WHERE temp.average_amount IS NOT NULL;