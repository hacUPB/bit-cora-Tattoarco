## Actividad 9


1. ¿En dónde está almacenado el miembro `valor` y el miembro `total` de la clase Contador?

El miembro `valor` y el miembro `total` de la clase Contador están almacenados en la memoria del objeto de la clase Contador.
![alt text](../Investigación/img/activida9.png)

2. ¿Qué puedes concluir de los miembros estáticos y de instancia de una clase en C++? ¿Cómo se gestionan en memoria? ¿Qué ventajas y desventajas tienen? ¿Cuándo es útil utilizarlos?

Los miembros estáticos de una clase en C++ son compartidos por todas las instancias de la clase, lo que significa que solo hay una copia de ese miembro en memoria. Por otro lado, los miembros de instancia son únicos para cada objeto y cada objeto tiene su propia copia de esos miembros.

En términos de gestión de memoria, los miembros estáticos se almacenan en una sección de memoria separada que es compartida por todas las instancias de la clase, mientras que los miembros de instancia se almacenan en la memoria asignada a cada objeto individual.

Las ventajas de los miembros estáticos incluyen la capacidad de compartir datos entre todas las instancias de la clase. Esto puede ser útil para contar el número de objetos creados o para almacenar información que es común a todas las instancias.

3. En el programa, en qué segmento de memoria se están almacenando c1, c2, c3 y Contador::total? Ten especial cuidado con la respuesta que das para el caso de c3, piensa de nuevo, qué es c3 y qué está almacenando. Ahora, responde de nuevo, en qué segmento de la memoria se está almacenando c3 y en qué segmento de la memoria se está almacenando el objeto al que apunta c3.

En el programa, c1 y c2 son objetos de la clase Contador y se almacenan en el segmento de memoria stack ya que son variables locales dentro de la función main. El miembro estático Contador::total se almacena en el segmento de memoria de datos (segmento de memeoria) ya que es compartido por todas las instancias de la clase.

c3 es un puntero a un objeto de la clase Contador. El puntero c3 en sí se almacena en el segmento de memoria stack, pero el objeto al que apunta c3 se almacena en el segmento de memoria heap, ya que se crea dinámicamente utilizando la palabra clave new.