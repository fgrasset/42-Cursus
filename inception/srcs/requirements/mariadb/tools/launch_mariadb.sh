#!/bin/bash


# Start MariaDB in secure initialization mode
mysqld --initialize --user=mysql --datadir=/var/lib/mysql;
chown -R mysql:mysql /var/lib/mysql;
chown -R mysql:mysql /run/mysqld;
mysqld --user=mysql --datadir=/var/lib/mysql &
pid=$!


# Wait briefly for initialization
sleep 10

# Configure MariaDB (using your variables from Script 1)
mysql -u root -p${SQL_ROOT_PASSWORD} -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "GRANT ALL PRIVILEGES ON *.* TO '${SQL_USER}'@'%';"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"

# Kill the temporary initialization process
kill "$pid"

# Run MariaDB in the foreground for proper execution
exec mysqld --user=mysql --datadir=/var/lib/mysql
