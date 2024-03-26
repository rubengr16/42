#!/bin/sh

sed -i "s/DB_NAME/$DB_NAME/" /tmp/testing.sql
sed -i "s/DB_USER/$DB_USER/" /tmp/testing.sql
sed -i "s/DB_PASSWORD/$DB_PASSWORD/" /tmp/testing.sql
