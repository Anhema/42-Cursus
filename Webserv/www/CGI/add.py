#!/usr/bin/python3

import cgi

# Crear una instancia de FieldStorage para manejar los datos del formulario
form = cgi.FieldStorage()

# Obtener los valores de los campos 'f_name' y 'email' del formulario
num1 = int(form.getvalue('num1', ''))  # Si no se proporciona 'f_name', asigna una cadena vacía
num2 = int(form.getvalue('num2', ''))  # Si no se proporciona 'email', asigna una cadena vacía

# Imprimir contenido HTML con los valores obtenidos del formulario
print("<html>")
print("<head><title>Resultado del formulario</title></head>")
print("<body>")
print("<h1>Resultado del formulario</h1>")
print(num1 + num2)
print("</body>")
print("</html>")