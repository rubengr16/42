# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/04/13 16:22:57 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ARG MARIADB_RUN_USER
ARG DB_NAME
ARG DB_USER
ARG DB_PASSWORD
ARG DB_DATA_DIR
ARG WP_NETWORK

RUN apk update && apk upgrade && apk add mariadb mysql-client

COPY /tools /tmp

RUN sh /tmp/init.sh

EXPOSE 3306

ENTRYPOINT mariadbd-safe --datadir=/data
