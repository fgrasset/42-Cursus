FROM debian:buster

RUN apt update -y && \
    apt upgrade -y && \
    apt-get install mariadb-server -y

RUN mkdir -p /run/mysqld /var/lib/mysql

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/launch_mariadb.sh /usr/local/launch_mariadb.sh

# Grant execute permission to the script
RUN chmod +x /usr/local/launch_mariadb.sh

EXPOSE 3306

# Start MariaDB on container startup
ENTRYPOINT ["sh", "/usr/local/launch_mariadb.sh"]
