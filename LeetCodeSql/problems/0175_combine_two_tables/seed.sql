DROP TABLE IF EXISTS Person;
DROP TABLE IF EXISTS Address;

CREATE TABLE Person (
  personId INTEGER,
  firstName TEXT,
  lastName TEXT
);

CREATE TABLE Address (
  addressId INTEGER,
  personId INTEGER,
  city TEXT,
  state TEXT
);

INSERT INTO Person (personId, lastName, firstName) VALUES (1, 'Wang', 'Allen');
INSERT INTO Person (personId, lastName, firstName) VALUES (2, 'Alice', 'Bob');

INSERT INTO Address (addressId, personId, city, state) VALUES (1, 2, 'New York City', 'New York');
INSERT INTO Address (addressId, personId, city, state) VALUES (2, 3, 'Leetcode', 'California');
