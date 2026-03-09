# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 21:29:25 by rgallego          #+#    #+#              #
#    Updated: 2026/01/01 06:13:38 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.23.2

RUN apk update && \
	apk add \
		nginx \
		openssl

COPY /tools /tmp

EXPOSE 443

ENTRYPOINT sh /tmp/entrypoint.sh
