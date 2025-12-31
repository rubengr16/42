set -e

if [ $(ls -1A /var/www/html | wc -l) -le 1 ]; then
    cd /var/www/html
    wget -O /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x /usr/local/bin/wp
    php -d memory_limit=512M /usr/local/bin/wp core download --version=6.9 --allow-root
    wp core install \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN}" \
        --admin_password="$(cat ${WP_ADMIN_PASSWORD_FILE})" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root >> /install.txt
    wp user create \
        ${WP_USER} ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=$(cat ${WP_USER_PASSWORD_FILE}) >> /create.txt
fi

php-fpm83 --nodaemonize