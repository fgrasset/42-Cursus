echo "Launch WordPress\n"

php-fpm7.3 -v

# waiting for MariaDB to start
while ! mariadb -u $MARIADB_USER --password=$MARIADB_PASS -h mariadb -P 3306 --silent; do
	sleep 5
	echo "Mariadb starting..."
done

# print database
echo "------------------\n"
mariadb -u $MARIADB_USER --password=$MARIADB_PASS -h mariadb -P 3306 -e "SHOW DATABASES;"
echo "------------------\n"

# installing WordPress
if [ -e /var/www/wordpress/wp-config.php ]
	then echo "wp-config already installed"
else

	# wp-cli
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp

	# wordpress
	cd /var/www/wordpress
	wp core download --allow-root

	# configuration wordpress
	wp config create --dbname=$MARIADB_DB_NAME --dbuser=$MARIADB_USER --dbpass=$MARIADB_PASS --dbhost=$WP_HOST --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
	wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
	wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASS --allow-root

fi

php-fpm7.3 -F
