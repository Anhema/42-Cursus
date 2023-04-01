##!/bin/bash
#
#if [ ! -f /var/lib/mysql/mariadb.kk ]; then
#	service mysql start
#    	until mysqladmin ping; do
#		sleep 2
#	done
#	mysql -u root -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
#	mysql -u root -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
#	mysql -u root -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$MYSQL_USER'@'%';"
#	mysql -u root -e "FLUSH PRIVILEGES;"
#	mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWAORD';FLUSH PRIVILEGES;"
#
#	sed -i "s|bind-address|#bind-address|g" /etc/mysql/mariadb.conf.d/50-server.cnf
#	cat /etc/mysql/mariadb.conf.d/50-server.cnf |grep "bind-add"
#
#	touch /var/lib/mysql/mariadb.kk
#else
#	echo "Database exits"
#fi
#
##killall mysqld
#usr/bin/mysqld_safe

sed -i "s/^bind-address\s*=.*$/#bind-address = 127.0.0.1/" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s/#\?port\s*=.*/port=3306/" /etc/mysql/mariadb.conf.d/50-server.cnf

echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
echo "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$MYSQL_USER'@'%';"
echo "FLUSH PRIVILEGES;"
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';"
