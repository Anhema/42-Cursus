#!/bin/bash


archivo_texto=".env"

# Leer el archivo de texto y exportar variables
while IFS='=' read -r clave valor; do
  if [[ ! $clave =~ ^\#.* ]] && [[ -n $clave ]]; then
    export "$clave=$valor"
  fi
done < "$archivo_texto"

archivo_original="./alertmanager/config.yml"
archivo_nuevo="./alertmanager/config_mod.yml"

# Aplicar todas las sustituciones en una sola pasada
sed -e "s/\${ALERTMANAGER_AUTH_USERNAME}/$ALERTMANAGER_AUTH_USERNAME/g" \
    -e "s/\${ALERTMANAGER_AUTH_PASSWORD}/$ALERTMANAGER_AUTH_PASSWORD/g" \
    -e "s/\${ALERTMANAGER_AUTH_RECEIVER}/$ALERTMANAGER_AUTH_RECEIVER/g" \
    $archivo_original > $archivo_nuevo
