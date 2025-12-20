set -x
if [ ! -d /data/mysql ]; then
	mariadb-install-db --skip-test-db

	if [ $? -ne 0 ]; then
		echo "mariadb-install-db command failed!"
		exit 1
	fi

	# DB_ROOT_PASSWORD=$(< /dev/urandom tr -dc a-zA-Z0-9 | head -c20)
	# echo "Please, copy and save the new root password: ${DB_ROOT_PASSWORD}"
	env
	echo ${DB_NAME}
	echo ${DB_USER}
	echo ${DB_USER_PASSWORD_FILE}
	echo $(cat ${DB_USER_PASSWORD_FILE})
	echo ${DB_ROOT_PASSWORD_FILE}
	echo $(cat ${DB_ROOT_PASSWORD_FILE})
	cat << EOF | mariadbd --bootstrap --skip-grant-tables=false

	CREATE DATABASE IF NOT EXISTS ${DB_NAME};
	CREATE USER IF NOT EXISTS '${DB_USER}'@'%'
		IDENTIFIED BY '$(cat /run/secrets/db_user_password)';
	GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
	DROP USER 'mysql'@'localhost';
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$(cat /run/secrets/db_user_password)';
	FLUSH PRIVILEGES;

EOF

	if [ $? -ne 0 ]; then
		echo "mariadbd database initialization and users setup failed!"
		exit 1
	fi

	# mkdir -p /run/mysqld
	# chown mysql:mysql /run/mysqld
fi
