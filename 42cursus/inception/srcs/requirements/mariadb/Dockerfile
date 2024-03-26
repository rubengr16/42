# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/03/26 20:07:26 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ARG DB_NAME DB_USER DB_PASSWORD 

RUN apk update && apk add mysql mysql-client

RUN --mount=type=bind,source=/tools,target=/tmp,rw\
	sh /tmp/substitute.sh &&\
	mariadb-install-db --no-defaults --extra-file=/tmp/testing.sql --skip-test-db --user=mysql

# COPY /tools .

# RUN echo $DB_NAME

EXPOSE 3306

ENTRYPOINT mariadbd-safe --datadir=/data
