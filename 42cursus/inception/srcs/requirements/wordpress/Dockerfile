# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:58:47 by rgallego          #+#    #+#              #
#    Updated: 2025/12/26 12:52:48 by rgallego         ###   ########.fr        #
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
		php83-phar \
		php83-fpm \
		php83-mysqli\
	ln -s /usr/bin/php83 /usr/bin/php

RUN wget -O /usr/local/bin/wp/wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.pharhttps://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.pharhttps://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.pharhttps://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.pharhttps://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	chmod +x /usr/local/bin/wp/wp-cli.phar
	
COPY /tools /tmp

EXPOSE 9000

ENTRYPOINT sh /tmp/entrypoint.sh
