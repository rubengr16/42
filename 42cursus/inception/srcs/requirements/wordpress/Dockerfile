# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:58:47 by rgallego          #+#    #+#              #
#    Updated: 2024/04/22 22:15:55 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.23.2

ARG DB_NAME \
	DB_USER \
	DB_PASSWORD \
	DB_HOST \
	FAST_CGI_ORIGIN_HOST

RUN apk update && \
	apk upgrade && \
	apk add \
		wget \
		php83 \
		php83-fpm \
		php83-mysqli

COPY /tools /tmp

EXPOSE 9000

ENTRYPOINT sh /tmp/start-php-fpm.sh
