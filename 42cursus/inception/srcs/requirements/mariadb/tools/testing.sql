CREATE DATABASE IF NOT EXISTS DB_NAME;
CREATE ROLE IF NOT EXISTS 'wp_role';
GRANT ALL ON DB_NAME.* to 'wp_role';
CREATE USER IF NOT EXISTS DB_USER\
	IDENTIFIED BY DB_PASSWORD\
	DEFAULT ROLE 'wp_role';
FLUSH PRIVILEGES;
