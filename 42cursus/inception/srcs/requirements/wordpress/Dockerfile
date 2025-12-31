# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:58:47 by rgallego          #+#    #+#              #
#    Updated: 2025/12/31 18:16:44 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.23.2

RUN apk update && \
	apk upgrade && \
	apk add \
		php83 \
		php83-phar \
		php83-fpm \
		php83-mysqli \
		php83-mbstring \
		php83-iconv \
		php83-json \
		php83-curl \
		php83-zip \
		php83-openssl \
		php83-session && \
	ln -s /usr/bin/php83 /usr/bin/php

COPY /tools /tmp

EXPOSE 9000

ENTRYPOINT sh /tmp/entrypoint.sh
