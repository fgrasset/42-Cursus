FROM debian:buster

EXPOSE 3306

RUN apt update -y && \
    apt upgrade -y && \
    apt-get install mariadb-server -y

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY launch_mariadb.sh /mariadb/launch_mariadb.sh

ENV SQL_USER=${SQL_USER}
ENV SQL_PASSWORD=${SQL_PASSWORD}
ENV SQL_DATABASE=${SQL_DATABASE}
ENV SQL_ROOT_PASSWORD=${SQL_ROOT_PASSWORD}

# Grant execute permission to the script
RUN chmod +x /mariadb/launch_mariadb.sh

# Start MariaDB on container startup
CMD ["./mariadb/launch_mariadb.sh"]
