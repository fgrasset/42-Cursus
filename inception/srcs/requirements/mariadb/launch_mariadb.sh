#!/bin/bash

# Ensure MariaDB is not already running (prevents conflicts)
if ! pgrep -x "mysqld" > /dev/null
then
  # Start MariaDB in secure initialization mode
  mysqld --initialize-insecure --user=mysql --datadir=/var/lib/mysql &
  pid=$!

  # Wait briefly for initialization
  sleep 5

  # Configure MariaDB (using your variables from Script 1)
  mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
  mysql -e "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};"
  mysql -e "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
  mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${SQL_USER}'@'%';"
  mysql -e "FLUSH PRIVILEGES;"

  # Kill the temporary initialization process
  kill "$pid"
fi

# Run MariaDB in the foreground for proper execution
exec mysqld_safe
