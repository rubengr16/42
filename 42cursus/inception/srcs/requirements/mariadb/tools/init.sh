if [ ! -d /data/mysql ]; then
	mariadb-install-db --skip-test-db

	if [ $? -ne 0 ]; then
		echo "mariadb-install-db command failed!"
		exit 1
	fi

	DB_ROOT_PASSWORD=$(< /dev/urandom tr -dc a-zA-Z0-9 | head -c20)
	echo "Please, copy and save the new root password: ${DB_ROOT_PASSWORD}"

	cat << EOF | mariadbd --bootstrap --skip-grant-tables=false

	CREATE DATABASE IF NOT EXISTS ${DB_NAME};
	CREATE USER IF NOT EXISTS '${DB_USER}'@'${WP_NETWORK}'
		IDENTIFIED BY '${DB_PASSWORD}';
	GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'${WP_NETWORK}';
	DROP USER 'mysql'@'localhost';
	ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
	FLUSH PRIVILEGES;

EOF

	if [ $? -ne 0 ]; then
		echo "mariadbd database initialization and users setup failed!"
		exit 1
	fi

fi
