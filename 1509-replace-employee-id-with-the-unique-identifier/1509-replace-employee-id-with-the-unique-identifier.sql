# Write your MySQL query statement below
select EMPUNI.unique_id as unique_id , name from EmployeeUNI as EMPUNI
right join Employees as EMP
on EMP.id = EMPUNI.id