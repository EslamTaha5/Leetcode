# Write your MySQL query statement below
select W.id from Weather W, Weather W2
where W2.recordDate = subdate(W.recordDate, Interval 1 day) and W.temperature > w2.temperature;