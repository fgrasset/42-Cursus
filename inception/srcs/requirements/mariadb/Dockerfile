FROM debian:buster

EXPOSE 3306

RUN apt update -y && \
    apt upgrade -y && \
    apt-get install -y mariadb-server \
	mariadb-client \
	vim
	#&& rm -rf /var/lib/apt/lists/*
	#TODO: check why

RUN mkdir -p /run/mysqld /var/lib/mysql

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY launch_mariadb.sh /usr/local/launch_mariadb.sh

ENV SQL_USER=${SQL_USER}
ENV SQL_PASSWORD=${SQL_PASSWORD}
ENV SQL_DATABASE=${SQL_DATABASE}
ENV SQL_ROOT_PASSWORD=${SQL_ROOT_PASSWORD}

# Grant execute permission to the script
RUN chmod +x /usr/local/launch_mariadb.sh

# Start MariaDB on container startup
ENTRYPOINT ["sh", "/usr/local/launch_mariadb.sh"]
