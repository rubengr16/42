# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/04/05 21:19:07 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ARG DB_NAME DB_USER DB_PASSWORD DB_ROOT_PASSWORD

RUN apk update && apk add mariadb mysql-client

# RUN --mount=type=bind,source=/tools,target=/tmp,rw\
# 	sh /tmp/substitute.sh &&\
# 	mariadb-install-db --no-defaults --skip-grant-tables=false\
# 		--extra-file=/tmp/testing.sql --skip-test-db
RUN mariadb-install-db --no-defaults --skip-test-db --user=mysql

EXPOSE 3306

COPY /tools /tmp

RUN sh /tmp/substitute.sh

# ENTRYPOINT mariadbd-safe --datadir=/data --init-file=/tmp/init.sql

# cat  << EOF | mariadbd --datadir=/data --bootstrap

# FLUSH PRIVILEGES;

# ALTER USER 'root'@'localhost' IDENTIFIED BY '123465gfgj';

# CREATE OR REPLACE DATABASE wp_db;

# CREATE USER 'wp' IDENTIFIED BY '12344356';
# GRANT ALL PRIVILEGES ON *.* TO 'wp';

# EOF

cat  << EOF | mariadbd --datadir=/data --bootstrap

FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS DB_NAME;
CREATE ROLE IF NOT EXISTS 'wp_role';
GRANT ALL PRIVILEGES ON DB_NAME.* to 'wp_role';
CREATE USER IF NOT EXISTS DB_USER
	IDENTIFIED BY 'DB_PASSWORD';
GRANT 'wp_role' TO DB_USER;

EOF
