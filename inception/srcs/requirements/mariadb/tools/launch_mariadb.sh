#!/bin/bash

# Initialise the database
mysqld --initialize --user=mysql --datadir=/var/lib/mysql;

# Modifie the owners and groups of the directories
chown -R mysql:mysql /var/lib/mysql;
chown -R mysql:mysql /run/mysqld;

# Launch of mariadb in the background
mysqld --user=mysql --datadir=/var/lib/mysql &

pid=$!

# Waiting for the end of the mariadb launch
sleep 10

# Configure MariaDB (securely using environment variables)
mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
mysql -u root -e "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};"
mysql -u root -e "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO '${SQL_USER}'@'%';"
mysql -u root -e "FLUSH PRIVILEGES;"

# Run MariaDB in the foreground
exec mysqld --user=mysql --datadir=/var/lib/mysql
