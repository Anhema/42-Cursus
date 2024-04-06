#!/bin/bash

# Ruta al archivo de secrets
secrets_file="./secrets.txt"

# Ruta al archivo de plantilla de salida (asegúrate de incluir el nombre del archivo)
template_file="./env.ctmpl"

# Iniciar o limpiar el archivo de plantilla
> "$template_file"

# Leer cada línea del archivo secrets y generar la plantilla
while IFS='=' read -r key value; do
    echo "{{ with secret \"secret/data/myapp/$key\" }}$key={{ .Data.data.value }}{{ end }}" >> "$template_file"
done < "$secrets_file"

