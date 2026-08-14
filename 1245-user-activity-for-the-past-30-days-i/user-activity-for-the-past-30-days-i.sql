# Write your MySQL query statement below

SELECT Activity.activity_date as day, COUNT(DISTINCT user_id) as active_users FROM Activity WHERE Activity.activity_date BETWEEN '2019-06-28' AND '2019-07-27' GROUP BY(Activity.activity_date);