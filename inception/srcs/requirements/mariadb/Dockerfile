FROM debian:buster

RUN apt update -y && apt upgrade -y
RUN apt-get install -y mariadb-server procps

EXPOSE 3306

RUN mkdir -p /run/mysqld /var/lib/mysql

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/launch_mariadb.sh /usr/local/launch_mariadb.sh
RUN chmod +x /usr/local/launch_mariadb.sh

ENTRYPOINT [ "sh", "/usr/local/launch_mariadb.sh" ]
