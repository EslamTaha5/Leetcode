# Write your MySQL query statement below
select A.machine_id, round(avg(B.timestamp - A.timestamp), 3) as processing_time from
activity A inner join activity B
on A.machine_id = B.machine_id and 
A.process_id = b.process_id and a.timestamp < b.timestamp 
group by machine_id