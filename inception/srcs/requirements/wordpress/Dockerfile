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

# RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
# RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_fr.tar.gz

RUN chown -R www-data:www-data /var/www
RUN chmod -R 755 /var/www

COPY www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY wp_start.sh /usr/local/wp_start.sh
RUN chmod +x /usr/local/wp_start.sh

EXPOSE 9000

ENTRYPOINT ["sh", "/usr/local/wp_start.sh"]
