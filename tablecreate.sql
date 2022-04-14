CREATE TABLE inventory (productId int PRIMARY KEY, productName VARCHAR(50), quantity INTEGER);
CREATE TABLE orderHistory (CustomerId int PRIMARY KEY, productId int, lastName VARCHAR(50), orderDate date);
CREATE TABLE customers (CustomerId int PRIMARY KEY, userName VARCHAR(50), firstName VARCHAR(50), lastName VARCHAR(50), address VARCHAR(50));