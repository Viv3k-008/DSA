CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
        SELECT distinct Salary
        FROM Employee E1
        WHERE (
            SELECT COUNT(DISTINCT E2.Salary)
            FROM Employee E2
            WHERE E2.Salary > E1.Salary
        ) = N-1
  );
END