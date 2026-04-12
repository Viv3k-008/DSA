CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare M int;
  declare result int;

  set M = N-1;
  set result = (

     select distinct salary 
     from Employee
     order by salary desc
     limit 1 offset M

  );

  return result;
END