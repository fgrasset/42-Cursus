echo "Launch MariaDB\n"

# initialize mariadb
mysqld --initialize --user=mysql --datadir=/var/lib/mysql;

chown -R mysql:mysql /var/lib/mysql;
chown -R mysql:mysql /run/mysqld;

# launching mariadb
mysqld --user=mysql --datadir=/var/lib/mysql &
pid=$!
sleep 10

# Configuration mariadb
mysql -u root -p${MARIADB_ROOT_PASSWORD} -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"
mysql -u root -p${MARIADB_ROOT_PASSWORD} -e "CREATE DATABASE IF NOT EXISTS ${MARIADB_DB_NAME};"
mysql -u root -p${MARIADB_ROOT_PASSWORD} -e "CREATE USER IF NOT EXISTS '${MARIADB_USER}' IDENTIFIED BY '${MARIADB_PASS}';"
mysql -u root -p${MARIADB_ROOT_PASSWORD} -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIADB_USER}';"
mysql -u root -p${MARIADB_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"

# # Affichage des bases de données dans le terminal
# echo "------------------\n"
# mysql -u root -p${MARIADB_ROOT_PASSWORD} -e "SHOW DATABASES;"
# echo "------------------\n"
# mysql -u root -p${MARIADB_ROOT_PASSWORD} -e "SELECT User FROM mysql.user"
# echo "------------------\n"

# Kill mysql
kill "$pid"
exec mysqld --user=mysql --datadir=/var/lib/mysql
