# TC1031-Integral-B

# Programa para obtener la ruta más corta de un servicio de envío de un puerto a otro.

Se cargarán los datos al grafo en el main por medio de la función insertarVertice() e insertarArista().  
Se le desplegará un menú al usuario con distintas funciones como conocer el puerto de salida y destino, los horarios, y calcular ruta. 

# SICT0302B - Toma de decisiones 

**Usa grafos para hacer análisis de información**

Se crea una lista de adyacencia por medio de la función listaAdyacencia() que permitirá almacenar los datos. 

**Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema** 

Se resolverá mediante el uso de la función calcularRuta() que será realizada mediante el método de búsqueda en anchura BFS que funciona mejor para calcular las rutas con grafos. 

**Usa un algoritmo de hashing adecuado para resolver un problema**

Se desarrolló una tabla Hash que contendrá los datos nombre del puerto y la hora a la que salen sus barcos, se realiza el recorrido por medio de el nombre del puerto para arrojar la hora de partida. 

# SICT0303B - Implementa acciones científicas 

**Implementa mecanismos para consultar información de las estructuras correctos**

Mecanismos para consultar información:

grafos.h: La función calcularRuta() realiza una búsqueda en anchura para calcular la ruta más corta de puerto a otro. 

hash.h: Se utilizó el método tostring para poder imprimir el hash de los puertos con su hora de partida. Además, se extrajo el valor proporcionado por el usuario mediante el método get. 

**Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes**

BFS: El algoritmo recorrerá los nodos y los bordes de la lista de adyacencia. En el peor de los casos, deberá recorrer todos. Considerando n como el número de nodos, y b como el número de bordes, su complejidad temporal es de O(n+b).

crear: La complejidad temporal es de O(n) para el peor de los casos ya que irá creando el hash por cada dato que se le ingrese.

listaAdyacencia():El algoritmo leerá los datos, dependerá de la cantidad de datos que se agregaron. Sucomplejidad temporal es de O(n) para el peor de los casos.

get: El algoritmo obtendrá el índice para key, la complejidad temporal es de O(n) para el peor de los casos porque si existe alguna colisión, recorrerá toda la tabla hasta encontrar el valor. La complejidad temporal es de O(n) para el peor de los casos.



