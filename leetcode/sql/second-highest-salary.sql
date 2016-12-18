# Using max() will return a NULL if the value doesn't exist. So there is no need to UNION a NULL.
SELECT max(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT max(Salary) FROM Employee);