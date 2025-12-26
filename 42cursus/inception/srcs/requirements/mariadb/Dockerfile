# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 17:52:14 by rgallego          #+#    #+#              #
#    Updated: 2025/12/26 12:00:48 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.23.2

RUN apk update && \
    apk upgrade && \
    apk add \
        mariadb \
        mysql-client

COPY /tools /tmp

RUN sh /tmp/create-config.sh 

EXPOSE 3306

ENTRYPOINT sh /tmp/entrypoint.sh
