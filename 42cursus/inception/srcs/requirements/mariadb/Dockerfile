# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2024/04/25 19:56:42 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

RUN apk update && apk upgrade && apk add mariadb mysql-client

COPY /tools /tmp

ARG DB_NAME
ARG DB_USER

RUN sh /tmp/create-config.sh 
RUN --mount=type=secret,id=db_user_password \
    --mount=type=secret,id=db_root_password \
    sh /tmp/init.sh

EXPOSE 3306

ENTRYPOINT mariadbd-safe
