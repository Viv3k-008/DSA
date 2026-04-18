CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
     select distinct e1.salary
     from Employee e1
     where (
        select count(distinct e2.salary)
        from Employee e2
        where e2.salary > e1.salary
     ) = N-1

  );
END