# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 21:29:25 by rgallego          #+#    #+#              #
#    Updated: 2024/03/07 21:35:59 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19.1

RUN apk update && apk add nginx && apk add openssl

RUN openssl req \
	-newkey rsa:2048 -nodes -x509 -days 365 \
	-keyout /etc/ssl/private/certificate.key \
	-out /etc/ssl/certificate.crt \
	-subj "/O=42Madrid/OU=Student/CN=rgallego/C=ES/ST=MD"

COPY conf/nginx.conf /etc/nginx/

COPY tools/index.html /var/www/html/

EXPOSE 443

ENTRYPOINT nginx
