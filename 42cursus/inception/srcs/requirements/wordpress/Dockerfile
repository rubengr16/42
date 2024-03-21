# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:58:47 by rgallego          #+#    #+#              #
#    Updated: 2024/03/21 14:30:20 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

# RUN apk update && apk add 

WORKDIR /usr/share/webapps/

RUN wget https://wordpress.org/wordpress-6.4.3.tar.gz &&\
	tar -xzvf wordpress-6.4.3.tar.gz &&\
	rm wordpress-6.4.3.tar.gz
