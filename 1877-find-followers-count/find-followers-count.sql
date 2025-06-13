# Write your MySQL query statement below
select user_id,
count(follower_id) As followers_count
from followers
Group by user_id
order by user_id;