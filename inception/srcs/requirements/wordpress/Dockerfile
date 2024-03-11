FROM debian:buster

RUN apt update -y && \
	apt upgrade -y
RUN apt-get -y install wget
RUN apt-get install -y php7.3\
	php-fpm\
	php-mysql\
	mariadb-client

RUN mkdir -p /var/www/wordpress
RUN mkdir -p /run/php

RUN chown -R www-data:www-data /var/www
RUN chmod -R 755 /var/www

COPY conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY tools/wp_start.sh /usr/local/wp_start.sh
RUN chmod +x /usr/local/wp_start.sh

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

EXPOSE 9000

ENTRYPOINT ["sh", "/usr/local/wp_start.sh"]
