# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/03/17 19:00:50 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ENV DB_NAME="hola_juan"

RUN apk update && apk add mysql mysql-client

# COPY ./tools/testing.sql .

# RUN sed -i "s/\${DB_NAME}/${DB_NAME}/" testing.sql

# --mount=type=bind,source=./tools/testing.sql,target=/tmp/requirements.txt

RUN --mount=type=bind,source=/tools,target=/tmp,rw\
	sh /tmp/substitute.sh &&\
	mariadb-install-db --no-defaults --extra-file=/tmp/testing.sql --skip-test-db --user=mysql

ENTRYPOINT mariadbd-safe --datadir=/data
# ADD 

# RUN mysql-database 
# RUN mysqld ; mariadb drop user ... 



# CMD mysqld --database-dir=/data
