FROM debian:buster

RUN apt update -y
RUN apt upgrade -y
RUN apt-get install mariadb-server -y

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY launch_mariadb.sh /mariadb/launch_mariadb.sh

RUN chmod +x /mariadb/launch_mariadb.sh
RUN ./mariadb/launch_mariadb.sh
