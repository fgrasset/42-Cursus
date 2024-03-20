FROM debian:buster

RUN apt update -y && apt upgrade -y
RUN apt-get install -y wget
RUN apt-get -y install php7.3 php-fpm php-mysql mariadb-client

EXPOSE 9000

RUN	mkdir -p /var/www/wordpress
RUN mkdir -p /run/php

RUN chown -R www-data:www-data /var/www
RUN chmod -R 755 /var/www

COPY conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY tools/launch_wp.sh /usr/local/launch_wp.sh
RUN chmod +x /usr/local/launch_wp.sh

ENTRYPOINT ["sh", "/usr/local/launch_wp.sh"]
