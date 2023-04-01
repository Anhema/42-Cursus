FROM debian:buster

RUN apt-get update && \
    apt-get install -y nginx openssl

EXPOSE 443

COPY ./tools/example.crt /etc/nginx/	
COPY ./tools/example.key /etc/nginx/	
COPY ./conf/ /etc/nginx/conf.d	
#COPY ./data/ /var/www/html/

CMD ["nginx", "-g", "daemon off;"]
