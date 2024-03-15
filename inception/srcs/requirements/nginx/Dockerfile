FROM debian:buster

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y nginx openssl


RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes \
	-out /etc/nginx/ssl/fgrasset.crt -keyout /etc/nginx/ssl/fgrasset.key \
	-subj "/C=SW/ST=VS/L=Lausane/O=42/OU=42/CN=fgrasset.42.ch/emailAddress=fgrasset@student.42.fr"

RUN mkdir -p /var/run/nginx
RUN mkdir -p /var/www/wordpress

RUN chmod -R 755 /var/www/wordpress
RUN chown -R www-data:www-data /var/www/wordpress

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/launch_nginx.sh /usr/local/launch_nginx.sh
RUN chmod +x /usr/local/launch_nginx.sh


EXPOSE 443

ENTRYPOINT ["sh", "/usr/local/launch_nginx.sh"]
