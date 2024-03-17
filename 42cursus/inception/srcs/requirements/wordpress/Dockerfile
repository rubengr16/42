# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:58:47 by rgallego          #+#    #+#              #
#    Updated: 2024/03/17 21:21:47 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

RUN apk update && apk upgrade && apk add php83 php83-fpm

RUN mkdir -p /usr/share/webapps/

WORKDIR /usr/share/webapps/

RUN wget https://wordpress.org/latest.tar.gz &&\
	tar -xzvf latest.tar.gz &&\
	rm latest.tar.gz
