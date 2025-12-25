if [ $(ls -1A /var/www/html | wc -l) -le 1 ]; then
    cd /var/www/html
    wget https://wordpress.org/wordpress-6.9.tar.gz && \
        tar -xzf wordpress-6.9.tar.gz && \
        rm wordpress-6.9.tar.gz
        mv wordpress/* . && \
        rm -rf wordpress
fi
php-fpm83 --nodaemonize