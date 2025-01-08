El problema consiste en comparar dos listas de números enteros provenientes de un archivo, ordenarlas y calcular la suma de las diferencias absolutas entre elementos correspondientes de ambas listas. Este tipo de problema es útil en análisis de datos comparativos, como series temporales o mediciones experimentales, donde es necesario encontrar discrepancias entre dos conjuntos de datos.

Las estructuras de datos son vectores (std::vector): Se utilizan para almacenar dinámicamente los elementos de las listas. Los vectores son estructuras de datos flexibles y eficientes para el manejo de colecciones de datos de tamaño variable.

Resolución del Problema:

Los números enteros se leen desde un archivo llamado input.txt. Cada línea contiene un par de números que se almacenan en dos vectores separados (list1 y list2).
En caso de error al abrir el archivo o si las listas tienen tamaños desiguales, se lanza una excepción.
Procesamiento:

Ambas listas se ordenan utilizando el algoritmo std::sort, que organiza los elementos en orden ascendente para facilitar las comparaciones.
Posteriormente, se calculan las diferencias absolutas entre elementos correspondientes de las listas, sumándolas para obtener un valor total.
Despés se imprimen en la consola las listas ordenadas y la suma total de las diferencias absolutas entre sus elementos, proporcionando una visión clara del análisis realizado.
