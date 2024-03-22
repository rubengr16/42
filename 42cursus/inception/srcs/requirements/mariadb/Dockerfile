# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/03/22 21:15:45 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ARG DB_NAME DB_USER DB_PASSWORD DB_HOST

RUN apk update && apk add mysql mysql-client

# COPY ./tools/testing.sql .

# RUN sed -i "s/\${DB_NAME}/${DB_NAME}/" testing.sql

# --mount=type=bind,source=./tools/testing.sql,target=/tmp/requirements.txt

RUN --mount=type=bind,source=/tools,target=/tmp,rw\
	sh /tmp/substitute.sh &&\
	mariadb-install-db --no-defaults --extra-file=/tmp/testing.sql --skip-test-db --user=mysql

EXPOSE 3306

ENTRYPOINT mariadbd-safe --datadir=/data
# ADD 

# RUN mysql-database 
# RUN mysqld ; mariadb drop user ... 



# CMD mysqld --database-dir=/data
