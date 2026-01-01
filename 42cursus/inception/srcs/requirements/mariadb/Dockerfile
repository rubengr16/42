# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2026/01/01 06:11:58 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.23.2

RUN apk update && \
    apk upgrade && \
    apk add \
        mariadb \
        mysql-client

COPY /tools /tmp

EXPOSE 3306

ENTRYPOINT sh /tmp/entrypoint.sh
