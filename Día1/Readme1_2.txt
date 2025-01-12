Este problema se centra en calcular un puntaje de similitud entre dos listas de números enteros leídas desde un archivo. Este puntaje se basa en la frecuencia de aparición de los elementos de una lista en la otra, ponderada por el valor de los elementos. Este enfoque tiene aplicaciones en áreas como la detección de similitudes entre conjuntos de datos, la búsqueda de patrones repetidos o la comparación de inventarios.

Se utiliza una tabla hash, implementada con std::unordered_map, para registrar la frecuencia de los elementos en la segunda lista. Esto permite realizar búsquedas rápidas de elementos en tiempo promedio de O(1).

Se usan vectores (std::vector): Almacenan dinámicamente las listas de entrada, permitiendo gestionar datos de tamaño variable.
y las tablas Hash (std::unordered_map): Almacenan la frecuencia de los elementos de la segunda lista, optimizando la búsqueda y el cálculo del puntaje de similitud.

Resolución del Problema:

Los pares de números enteros se leen desde un archivo llamado input.txt. Los números de cada par se almacenan en dos vectores separados (list1 y list2).
Si ocurre un error al abrir el archivo, se lanza una excepción y el programa termina con un mensaje de error.

Se construye una tabla hash (unordered_map) que registra la frecuencia de cada número en list2.
Luego, se recorre list1, y para cada elemento se consulta su frecuencia en la tabla hash. El producto del valor del elemento y su frecuencia acumulada se suma al puntaje de similitud.
El puntaje de similitud calculado se imprime en la consola como resultado final, proporcionando una métrica cuantitativa que mide el grado de coincidencia entre las dos listas.

Este problema me dió pie a buscar una solución mejor a intentar crear desde cero una tabla hash, y gracias a él encontré la librería unordered_map, que implementa facilidades. 
Gracias a él, me he familiarizado con esta librería para usar tablas hash más a menudo.
