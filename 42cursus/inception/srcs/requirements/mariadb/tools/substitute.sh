#!/bin/sh

sed -i "s/DB_NAME/$DB_NAME/" /tmp/init.sql
sed -i "s/DB_USER/$DB_USER/" /tmp/init.sql
sed -i "s/DB_PASSWORD/$DB_PASSWORD/" /tmp/init.sql
