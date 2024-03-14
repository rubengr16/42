# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/03/14 21:07:26 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ARG DB_NAME=hola_juan

RUN apk update && apk add mysql mysql-client

RUN mariadb-install-db --no-defaults --skip-test-db --user=mysql

COPY ./tools/testing.sql .

ENTRYPOINT ["tail", "-f", "/dev/null"]
#ENTRYPOINT mariadbd-safe --init-file=testing.sql --datadir=/data 
# ADD 

# RUN mysql-database 
# RUN mysqld ; mariadb drop user ... 



# CMD mysqld --database-dir=/data
