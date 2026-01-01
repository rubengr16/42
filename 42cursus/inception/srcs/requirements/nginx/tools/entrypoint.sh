openssl req \
	-newkey rsa:2048 -nodes -x509 -days 365 \
	-keyout /etc/ssl/private/certificate.key \
	-out /etc/ssl/certificate.crt \
	-subj "/O=42Madrid/OU=Student/CN=rgallego/C=ES/ST=MD"
sed -i "s/SERVER_NAME/$SERVER_NAME/" /etc/nginx/nginx.conf
nginx