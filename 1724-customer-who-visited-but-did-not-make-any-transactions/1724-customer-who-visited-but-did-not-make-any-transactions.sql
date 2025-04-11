# Write your MySQL query statement below
select customer_id, count(*) as count_no_trans
from visits V left outer join transactions T
on  V.visit_id = T.visit_id
where transaction_id is NULL
group by customer_id