FROM	debian:buster

COPY	./tools/setup.sh ./tmp/setup.sh

RUN	apt-get update &&\
	apt-get install -y curl wget tar netcat vim &&\
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar &&\
	chmod +x wp-cli.phar &&\
	mv -f wp-cli.phar /usr/local/bin/wp &&\
	apt-get install -y php php-fpm php-mysql php-gd php-xml php-curl &&\
	apt-get clean &&\
	rm -rf /var/lib/apt/lists/*\ &&\
	service php7.3-fpm restart &&\
	chmod +x /tmp/setup.sh &&\
	apt -y remove  $(dpkg -l | grep -w apache2 | awk '{print $2}')

EXPOSE	9000

COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/
RUN	sed -i 's/^pid = \/run\/php\/php7\.3-fpm\.pid$/pid = \/var\/run\/php-fpm7.3.pid/' /etc/php/7.3/fpm/php-fpm.conf

CMD	["sh", "-c", "./tmp/setup.sh && /usr/sbin/php-fpm7.3 -F"]
