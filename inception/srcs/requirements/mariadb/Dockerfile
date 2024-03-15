FROM debian:buster

#Installation de mariaDB
RUN apt update -y && apt upgrade -y
RUN apt-get install -y mariadb-server procps

#Creation du repertoire de travail. /var/lib/mysql est le data direcory
RUN mkdir -p /run/mysqld /var/lib/mysql

#Copie des fichiers de configuration et du script de démarrage
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/launch_mariadb.sh /usr/local/launch_mariadb.sh
RUN chmod +x /usr/local/launch_mariadb.sh

#Port de connexion
EXPOSE 3306

ENTRYPOINT [ "sh", "/usr/local/launch_mariadb.sh" ]
