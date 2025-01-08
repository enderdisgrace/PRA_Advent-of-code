El problema se centra en determinar el número de secuencias numéricas, leídas de un archivo, que cumplen condiciones específicas de "seguridad". Una secuencia es considerada segura si:
Las diferencias entre números consecutivos están en el rango [1, 3].
La secuencia es completamente ascendente o completamente descendente.
Si al eliminar un único número de la secuencia, cumple los dos criterios anteriores.
Este problema tiene aplicaciones en validación de datos, detección de anomalías y análisis de patrones en series numéricas.

Brute Force: Para verificar si una secuencia es segura tras eliminar un nivel, se prueba iterativamente quitando cada elemento y formando la secuencia restante. Este enfoque es de tipo fuerza bruta, ya que recorre todas las combinaciones posibles para dar con la adecuada. Si bien no es la técnina más eficiente en muchos casos, es la más sencilla de ver, y puesto que tiene ventajas y desventajas hemos considerado que es válida para el proyecto.

Resolución del Problema

Lectura de Datos:
El archivo input2.txt se abre mediante std::ifstream. Cada línea se convierte en una secuencia de números enteros, almacenados en un vector para su análisis.

Verificación de Seguridad:
Sin Eliminación-> La función is_safe evalúa si una secuencia es segura directamente, verificando las diferencias consecutivas y la uniformidad en su dirección (ascendente o descendente).
Con Eliminación-> Si una secuencia no es segura, se utiliza is_safe_with_one_removal, que genera subsecuencias al eliminar cada elemento y las evalúa individualmente.

Contador de Secuencias Seguras:
Si una secuencia cumple alguna de las condiciones anteriores, se incrementa el contador safes.

Finalmente el programa imprime el número total de secuencias seguras detectadas en el archivo, lo que permite evaluar la calidad y consistencia de los datos numéricos.













