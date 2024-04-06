#!/bin/bash

# Detener todos los contenedores de Docker
echo "Deteniendo todos los contenedores..."
 docker stop $( docker ps -aq)

# Eliminar todos los contenedores
echo "Eliminando todos los contenedores..."
 docker rm $( docker ps -aq)

# Eliminar todas las imágenes de Docker
echo "Eliminando todas las imágenes..."
 docker rmi $( docker images -q) --force

# Eliminar todos los volúmenes de Docker
echo "Eliminando todos los volúmenes..."
 docker volume rm $( docker volume ls -q)

# Eliminar todas las redes de Docker
echo "Eliminando todas las redes..."
 docker network rm $( docker network ls -q) 2> /dev/null

# Limpiar todos los recursos no utilizados (incluyendo imágenes, contenedores, volúmenes y redes)
echo "Ejecutando Docker system prune..."
 docker system prune -a -f --volumes

echo "Limpieza completa."

