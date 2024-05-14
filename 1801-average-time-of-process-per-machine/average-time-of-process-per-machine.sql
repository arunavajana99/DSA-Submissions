# Write your MySQL query statement below
select a.machine_id, round(avg(a.timestamp - b.timestamp),3) as processing_time
from (select * from Activity where activity_type = 'end') as a
left join (select * from Activity where activity_type = 'start') as b
on a.machine_id = b.machine_id
group by a.machine_id;