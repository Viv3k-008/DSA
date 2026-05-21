with maxTable as (
    select max(salary) as maxSal from employee
)

select max(e.salary) as SecondHighestSalary from employee e join maxTable m where e.salary < m.maxSal;