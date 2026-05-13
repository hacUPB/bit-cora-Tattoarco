## Actividad 4


### Parte 1

Luego de estudiar las unidades 1 y 2 de este curso y ver el video, escribe con tus propias palabras 

1. ¿Cuál es la diferencia entre una CPU y una GPU?

* `GPU:` Funciona con multiples nucleos en paralelo, creando elementos gráficos más elavorados. 
* `CPU:` Funciona para tareas secuenciales y pesadas, colo lo son los algoritmos y demás.


### Parte 2

1. ¿Cuáles son los tres pasos claves del pipeline de OpenGL? Explica en tus propias palabras cuál es el objetivo de cada paso.

* **Vertex shading:** Es el primer paso realizado por la `GPU`, su función es analizar y renderizar los datos que se muestran o no en pantalla. 
* **Restarización:** Funciona para "pintar" los triagulos, es la arte que hace que un videojuego no luzca como un plano don figuras geometricas sin color o textura. 
* **Fragment shading:**  Es el paso final, se encarga de darle color a cada fragmento, es decir, a cada pixel.

2. La gran novedad que introduce OpenGL moderno es el pipeline programable. ¿Qué significa esto? ¿Qué diferencia hay entre el pipeline fijo y el programable? ¿Qué ventajas le ves a esto? y si el pipeline es programable, ¿Qué tengo que programar?

El pipeline programable es aquel que permite a los desarrolladores escribir su propio código para cada etapa del proceso de renderizado, en lugar de depender de un conjunto fijo de funciones predefinidas. La diferencia entre el pipeline fijo y el programable radica en la flexibilidad que ofrece el programable, ya que permite personalizar cada etapa del proceso de renderizado según las necesidades específicas del proyecto. Las ventajas de esto incluyen la capacidad de crear efectos visuales únicos, optimizar el rendimiento y adaptar el proceso de renderizado a diferentes tipos de contenido. Si el pipeline es programable, tengo que programar los shaders, que son pequeños programas que se ejecutan en la GPU para realizar tareas específicas en cada etapa del pipeline, como el vertex shader para procesar vértices y el fragment shader para procesar fragmentos.


3. Si fueras a describir el proceso de rasterización ¿Qué dirías?

La rasterización es el proceso mediante el cual se convierten los objetos 3D en una representación 2D en la pantalla. Durante este proceso, los triángulos que componen los objetos 3D se "pintan" o "rasterizan" en la pantalla, asignando colores y texturas a cada fragmento o pixel.

4. ¿Qué son los fragmentos? ¿Es lo mismo un fragmento que un pixel? ¿Por qué?

Los fragmentos son los elementos que se generan durante el proceso de rasterización y representan la información necesaria para determinar el color y la profundidad de cada pixel en la pantalla. Un fragmento no es lo mismo que un pixel, ya que un fragmento puede generar uno o más pixels dependiendo de su tamaño y posición en la pantalla. 

5. Explica qué problema resuelve el Z-buffer y ¿Qué es el depth test?

El `z-buffer` resuelve el problema de la distancia ente el renderizado y la cámara, con este buffer se puede determinar qué objetos están más cerca de la cámara y cuáles están más lejos, lo que permite renderizar correctamente las escenas 3D. El `depth test` es una prueba que se realiza durante el proceso de renderizado para determinar si un fragmento debe ser dibujado en la pantalla o no, basándose en su profundidad en relación con otros fragmentos.

6. ¿Por qué se presenta el problema de la aliasing? ¿Qué es el anti-aliasing?

El problema de aliasing se presenta cuando se renderizan objetos con bordes o detalles finos, lo que puede resultar en una apariencia pixelada o "escalonada". El anti-aliasing es una técnica utilizada para suavizar estas irregularidades y mejorar la calidad visual de los gráficos, reduciendo el efecto de aliasing al suavizar los bordes y mejorar la apariencia general de la imagen.

7. ¿Qué relación hay entre la iluminación y el fragment shader? Siempre es necesario tener en cuenta la iluminación en un fragment shader? o puedo hacer un fragment shader sin iluminación? Explica que implicaciones tiene esto.

El fragment shader es responsable de determinar el color final de cada fragmento, y la iluminación es un factor crucial en este proceso, ya que afecta cómo se perciben los colores y las sombras en la escena. No siempre es necesario tener en cuenta la iluminación en un fragment shader, ya que se pueden crear efectos visuales específicos sin ella, como un estilo de arte plano o un efecto de silueta. Sin embargo, omitir la iluminación puede resultar en una apariencia menos realista y puede limitar la capacidad de crear efectos visuales complejos.

8. ¿Qué implica para la GPU que una aplicación tenga múltiples fuentes de iluminación?

Tener múltiples fuentes de iluminación implica que la GPU debe realizar cálculos adicionales para cada fuente de luz, lo que puede aumentar la carga de trabajo y afectar el rendimiento. La GPU debe calcular cómo cada fuente de luz interactúa con los objetos en la escena, lo que puede resultar en un mayor tiempo de renderizado y una mayor demanda de recursos. Sin embargo, también permite crear escenas más realistas y visualmente atractivas al simular diferentes tipos de iluminación y sombras.


### Parte 3

Implementa el código anterior en tu máquina y captura pantalla del resultado. Pero antes de hacerlo trata de predecir qué va a pasar.

Creo que el resultado va a ser una ventana con un fondo verde, y múltiples triángulos.

![alt text](./img/ACTIVIDAD4.png)



