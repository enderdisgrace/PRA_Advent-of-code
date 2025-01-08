El problema abordado evalúa la seguridad de ciertas secuencias de números enteros leídas desde un archivo. Se considera que una secuencia es "segura" si las diferencias entre números consecutivos están entre 1 y 3 (inclusive); y la secuencia es completamente ascendente o completamente descendente.

Brute Force: El programa evalúa cada secuencia línea por línea, comprobando los valores uno a uno para determinar si cumplen los criterios definidos.

Resolución del Problema

El programa utiliza std::ifstream para abrir el archivo input2.txt. Cada línea se lee como una cadena y se procesa mediante std::istringstream para convertirla en una secuencia de números enteros.
Para cada línea, se evalúa la diferencia entre números consecutivos:
Si alguna diferencia está fuera del rango [1, 3], la secuencia se considera no segura y se abandona su evaluación.
Se rastrea si la secuencia es completamente ascendente o descendente mediante un contador ascend:
Se incrementa si el número actual es mayor que el anterior.
Se decrementa si el número actual es menor que el anterior.
Si al final todos los números son ascendentes o todos son descendentes, se incrementa el contador de secuencias seguras (safes).
El programa retorna el número total de secuencias "seguras" detectadas en el archivo, lo que permite evaluar cuántas líneas cumplen con los criterios establecidos.
