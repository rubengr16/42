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

FROM alpine:3.19.1

ARG DB_NAME\
	DB_USER\
	DB_PASSWORD\
	DB_HOST\
	FAST_CGI_ORIGIN_HOST

RUN apk update && apk upgrade && apk add php83 php83-fpm

WORKDIR /usr/share/webapps/

RUN wget https://wordpress.org/wordpress-6.4.3.tar.gz &&\
	tar -xzvf wordpress-6.4.3.tar.gz &&\
	rm wordpress-6.4.3.tar.gz &&\
	cd wordpress

COPY /config/wp-config.php .

RUN mv wp-config-sample.php wp-config.php &&\
	sed -i "s/database_name_here/$DB_NAME/" wp-config-sample.php &&\
	sed -i "s/username_here/$DB_USER/" wp-config-sample.php &&\
	sed -i "s/password_here/$DB_PASSWORD/" wp-config-sample.php &&\
	sed -i "s/localhost/$DB_HOST/" wp-config-sample.php

# Doubts on this, if it needs to be changed to 0.0.0.0
# Doubts on how to manage the user, if I need to change them
RUN sed -i "s/127.0.0.1/$FAST_CGI_SRC_HOST/" /etc/php83/php-fpm.d/www.conf

# EXPOSE 9000

# Fails, to be tested with the docker compose
ENTRYPOINT php-fpm83 --nodaemonize
