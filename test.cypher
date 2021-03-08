CREATE CONSTRAINT ON (i:Id) ASSERT i.id IS UNIQUE;
CREATE CONSTRAINT ON (f:Friends) ASSERT f.friends IS UNIQUE;


USING PERIODIC COMMIT
LOAD CSV WITH HEADERS FROM
'file:////home/sonnh/Downloads/Telegram%20Desktop/100000.csv' AS line
WITH line.`id` AS id
LIMIT 1
RETURN id

CREATE (id:Id {})