# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 21:29:25 by rgallego          #+#    #+#              #
#    Updated: 2024/04/25 19:55:11 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.23.2

RUN apk update && \
	apk add \
		nginx \
		openssl

RUN openssl req \
	-newkey rsa:2048 -nodes -x509 -days 365 \
	-keyout /etc/ssl/private/certificate.key \
	-out /etc/ssl/certificate.crt \
	-subj "/O=42Madrid/OU=Student/CN=rgallego/C=ES/ST=MD"

# COPY conf/nginx.conf /etc/nginx/

# RUN sed -i "s/FAST_CGI_DST_HOST/$FAST_CGI_DST_HOST/" /etc/nginx/nginx.conf

# COPY tools/index.html /var/www/html/

EXPOSE 443

ENTRYPOINT nginx
