/*
 * This is my way and it's stupid and simple.
 * A good and clean SQL statement I see:
 *     SELECT `FirstName`, `LastName`, `City`, `State`
 *     FROM `Person`
 *     LEFT JOIN `Address`
 *     USING(`PersonId`)
 */

SELECT Person.FirstName, Person.LastName, Address.City, Address.State
FROM Person LEFT JOIN Address
ON Person.PersonId = Address.PersonId;