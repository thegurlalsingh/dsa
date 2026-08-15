WITH temp AS (
    SELECT MovieRating.user_id, COUNT(*) as cnt, Users.name FROM MovieRating, Users WHERE MovieRating.user_id = Users.user_id GROUP BY MovieRating.user_id ORDER BY cnt DESC, Users.name ASC LIMIT 1
),
temp2 AS (
    SELECT MovieRating.movie_id, AVG(MovieRating.rating) as avg, Movies.title FROM MovieRating, Movies WHERE MovieRating.created_at BETWEEN '2020-02-01' AND '2020-02-29' AND MovieRating.movie_id = Movies.movie_id GROUP BY MovieRating.movie_id ORDER BY avg DESC, Movies.title ASC LIMIT 1
)

SELECT temp.name AS results FROM temp 

UNION ALL

SELECT temp2.title AS results FROM temp2;



