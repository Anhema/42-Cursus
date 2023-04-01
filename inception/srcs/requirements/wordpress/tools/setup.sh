#!/bin/sh

mkdir -p /var/www/html/

echo "Executing"
while ! nc -z mariadb 3306; do
  echo "Checking id 'db' container is on..."
  sleep 1
done
cd /var/www/html
wp core download --locale=es_ES --allow-root
wp --path=/var/www/html config create --dbname=${DB_NAME} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=mariadb --locale=es_ES --allow-root --skip-check
wp core install --path=/var/www/html  --url=${DOMAIN_NAME} --title="Welcone to aherrero's wordpress" --admin_name=${WP_ADMIN_USER} --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email="aherrero@student.42urduliz.com" --skip-email --allow-root
wp --path=/var/www/html theme install https://downloads.wordpress.org/theme/zeever.1.0.9.zip --allow-root
wp --path=/var/www/html theme activate zeever --allow-root
echo "Unable to reach end of file"

