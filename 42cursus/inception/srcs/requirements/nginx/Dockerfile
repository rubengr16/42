FROM alpine:3.19.1
# FROM debian:buster
# RUN apt-get update && apt-get install -y nginx && apt-get install -y openssl

RUN apk update && apk add nginx && apk add openssl

RUN openssl req \
	-newkey rsa:2048 -nodes -x509 -days 365 \
	-keyout /etc/ssl/private/certificate.key \
	-out /etc/ssl/certificate.crt \
	-subj "/O=42Madrid/OU=Student/CN=rgallego/C=ES/ST=MD"

COPY conf/nginx.conf /etc/nginx/

COPY tools/index.html /var/www/html/

ENTRYPOINT nginx
