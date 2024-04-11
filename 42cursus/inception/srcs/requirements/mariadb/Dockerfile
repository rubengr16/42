# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/04/11 20:31:03 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

ARG DB_NAME DB_USER DB_PASSWORD

RUN apk update && apk upgrade && apk add mariadb mysql-client

COPY /tools /tmp

RUN sh /tmp/init.sh

EXPOSE 3306

ENTRYPOINT mariadbd-safe --datadir=$(DB_DATA_DIR)
