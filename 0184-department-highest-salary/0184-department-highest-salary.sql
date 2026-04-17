select d.name as Department , e.name as Employee , e.salary as Salary
from Employee e inner join Department d
on e.departmentId = d.id where e.salary = (
    select max(x.salary) 
    from Employee x
    where x.departmentId = e.departmentId
)
