set -e

if [ $(ls -1A /var/www/html | wc -l) -le 1 ]; then
    cd /var/www/html
    # wget https://wordpress.org/wordpress-6.9.tar.gz && \
    #     tar -xzf wordpress-6.9.tar.gz && \
    #     rm wordpress-6.9.tar.gz
    #     mv wordpress/* . && \
    #     rm -rf wordpress
    wp core download --version=6.9 --allow-root
    wp core install \
    --url="${SITE_URL}" \
    --title="${SITE_TITLE}" \
    --admin_user="${ADMIN_USER}" \
    --admin_password="${ADMIN_PASSWORD}" \
    --admin_email="${ADMIN_EMAIL}" \
    --skip-email \
    --allow-root
fi
php-fpm83 --nodaemonize