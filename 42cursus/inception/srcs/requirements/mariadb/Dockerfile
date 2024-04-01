# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/04/02 00:18:05 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ARG DB_NAME DB_USER DB_PASSWORD DB_ROOT_PASSWORD

RUN apk update && apk add mysql mysql-client

# RUN --mount=type=bind,source=/tools,target=/tmp,rw\
# 	sh /tmp/substitute.sh &&\
# 	mariadb-install-db --no-defaults --skip-grant-tables=false\
# 		--extra-file=/tmp/testing.sql --skip-test-db
RUN mariadb-install-db --no-defaults --skip-test-db --user=mysql

EXPOSE 3306

COPY /tools /tmp

RUN sh /tmp/substitute.sh

ENTRYPOINT mariadbd-safe --datadir=/data --init-file=/tmp/init.sql
