FROM debian:buster

RUN apt-get update && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*


RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes \
	-out /etc/nginx/ssl/fgrasset.crt -keyout /etc/nginx/ssl/fgrasset.key \
	-subj "/C=FR/ST=IDF/L=Lausanne/O=42/OU=42/CN=localhost"

COPY nginx.conf /etc/nginx/nginx.conf
COPY index.html /var/www/html

EXPOSE 443

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html
CMD ["nginx", "-g", "daemon off;"]
