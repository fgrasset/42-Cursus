FROM debian:buster

RUN apt-get update && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

EXPOSE 443

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/nginx/ssl/ssl-crt.crt -keyout /etc/nginx/ssl/ssl-key.key \
	-subj "/C=FR/ST=IDF/L=Lausanne/O=42/OU=42/CN=localhost/UID=localhost"

COPY nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html
CMD ["nginx", "-g", "daemon off;"]
