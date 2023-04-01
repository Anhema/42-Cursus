FROM debian:buster

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    service mysql start

COPY ./tools/setup.sh ./
RUN	chmod +x setup.sh
EXPOSE 3306

CMD ["sh", "-c", "./setup.sh > ./setup.sql && mysqld --init-file=/setup.sql"]
