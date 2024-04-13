cat << EOF > /etc/my.cnf.d/mariadb-server.cnf

	#
	# These groups are read by MariaDB server.
	# Use it for options that only the server (but not clients) should see

	# this is read by the standalone daemon and embedded servers
	[server]

	# this is only for the mysqld standalone daemon
	[mysqld]
	user=mysql
	datadir=/data
	#skip-networking

	# Galera-related settings
	[galera]
	# Mandatory settings
	#wsrep_on=ON
	#wsrep_provider=
	#wsrep_cluster_address=
	#binlog_format=row
	#default_storage_engine=InnoDB
	#innodb_autoinc_lock_mode=2
	#
	# Allow server to accept connections on all interfaces.
	#
	bind-address=$(WP_NETWORK)
	#
	# Optional setting
	#wsrep_slave_threads=1
	#innodb_flush_log_at_trx_commit=0

	# this is only for embedded server
	[embedded]

	# This group is only read by MariaDB servers, not by MySQL.
	# If you use the same .cnf file for MySQL and MariaDB,
	# you can put MariaDB-only options here
	[mariadb]

	# This group is only read by MariaDB-10.5 servers.
	# If you use the same .cnf file for MariaDB of different versions,
	# use this group for options that older servers don't understand
	[mariadb-10.5]

EOF
