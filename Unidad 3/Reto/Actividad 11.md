## Actividad 11


### Parte 1

1. Explica con tus propias palabras qué es el stack y qué es el heap en C++.

- El `Stack` es la region de memoria en la que se almacenan las variables locales.
- El `Heap` es la region de memoria en la que se almacenan las variables dinámicas, es decir, aquellas que se crean con `new`.

2. Describe las tres formas de pasar parámetros a una función en C++ (valor, referencia y puntero). Para cada una, explica qué sucede en memoria y cuándo usarías cada método.

- Pasar por valor: se crea una copia de la variable y se pasa a la función. La función trabaja con esa copia, por lo que cualquier cambio no afecta a la variable original. Se almacena en el `Stack`. Se usa cuando no se necesita modificar la variable original.
- Pasar por referencia: se pasa la dirección de la variable a la función, lo que permite modificar la variable original. Se almacena en el `Stack`. Se usa cuando se necesita modificar la variable original o cuando se quiere evitar la sobrecarga de copiar grandes estructuras de datos.
- Pasar por puntero: se pasa un puntero a la variable, lo que también permite modificar la variable original. Se almacena en el `Stack` para el puntero y en el `Heap` para la variable a la que apunta si es dinámica. Se usa cuando se necesita modificar la variable original o cuando se trabaja con estructuras de datos dinámicas.

3. ¿Qué diferencia hay entre una variable local, una variable global y una variable local estática? ¿En qué segmento del mapa de memoria se almacena cada una?

- Variable local: se declara dentro de una función y solo es accesible dentro de esa función. Se almacena en el `Stack`.
- Variable global: se declara fuera de todas las funciones y es accesible desde cualquier parte del programa. Se almacena en el segmento de datos del programa.
- Variable local estática: se declara dentro de una función pero con la palabra clave `static`, lo que hace que su valor persista entre llamadas a la función. Se almacena en el segmento de datos del programa.

4. Explica qué es un objeto en C++ desde la perspectiva de memoria. ¿Dónde se almacenan los miembros de instancia y dónde los miembros estáticos?

Un objeto en C++ es una instancia de una clase que contiene miembros de datos (variables) y funciones miembro (métodos). Los miembros de instancia se almacenan en el `Heap` si el objeto se crea dinámicamente con `new`, o en el `Stack` si se crea como una variable local. Los miembros estáticos, por otro lado, se almacenan en el segmento de datos del programa, ya que son compartidos por todas las instancias de la clase.

### Parte 2: transferencia y análisis de situación nueva

Imagina que trabajas en un equipo de desarrollo de videojuegos y tu compañero te muestra este código problemático que está causando crashes en el juego:

```.c++
#include <iostream>
using namespace std;
class Enemigo {
		public:    
				static int totalEnemigos;    
				int vida;    
				int* armas;
		    Enemigo(int v) : vida(v) {        
				    totalEnemigos++;        
				    armas = new int[3];        
				    armas[0] = 10; 
				    armas[1] = 15; 
				    armas[2] = 20;    
				    }
				 };
		int Enemigo::totalEnemigos = 0;
		void crearEscuadron() {    
				for(int i = 0; i < 5; i++) {        
						Enemigo soldado(100);        
						soldado.vida -= 10;    
						}    
				cout << "Escuadrón creado. Total enemigos: " << Enemigo::totalEnemigos << endl;
				}
int main() {    
		crearEscuadron();    
		crearEscuadron();    
		return 0;
		}
```


1. Análisis de problemas: identifica al menos dos problemas serios en este código relacionados con el manejo de memoria. Explica por qué cada uno es problemático.

- El primer problema es que el constructor de la clase `Enemigo` asigna memoria dinámica para el arreglo `armas` pero no hay un destructor definido para liberar esa memoria. Esto causa una fuga de memoria cada vez que se crea un nuevo objeto `Enemigo`, lo que eventualmente puede llevar a que el programa se quede sin memoria disponible.
- El segundo problema es que la variable estática `totalEnemigos` se incrementa cada vez que se crea un nuevo objeto `Enemigo`, pero no se decrementa cuando los objetos son destruidos. Esto significa que el conteo de enemigos no refleja la cantidad real de enemigos activos en el juego, lo que puede causar confusión y errores en la lógica del juego.

2. Predicción de comportamiento: ¿Qué valor mostrará totalEnemigos después de ejecutar el programa? ¿Por qué ocurre esto?

Después de ejecutar el programa, el valor de `totalEnemigos` mostrará 10. Esto ocurre porque cada vez que se llama a la función `crearEscuadron()`, se crean 5 objetos `Enemigo`, y cada uno de esos objetos incrementa `totalEnemigos` en 1. Dado que `crearEscuadron()` se llama dos veces, el total se incrementa en 5 + 5 = 10. Sin embargo, como no hay un destructor para liberar la memoria ni un mecanismo para decrementar `totalEnemigos` cuando los objetos son destruidos, el conteo no refleja la cantidad real de enemigos activos.

3. Propuesta de solución: escribe una versión corregida de la clase Enemigo que solucione los problemas identificados. Explica brevemente cada cambio que hiciste.

```.c++
#include <iostream>
using namespace std;
class Enemigo {
		public:    
				static int totalEnemigos;    
				int vida;    
				int* armas;
		    Enemigo(int v) : vida(v) {        
				    totalEnemigos++;        
				    armas = new int[3];        
				    armas[0] = 10; 
				    armas[1] = 15; 
				    armas[2] = 20;    
				    }
		    ~Enemigo() {        
				    delete[] armas;        
				    totalEnemigos--;    
				    }
				 };
		int Enemigo::totalEnemigos = 0;
		void crearEscuadron() {    
				for(int i = 0; i < 5; i++) {        
						Enemigo soldado(100);        
						soldado.vida -= 10;    
						}    
				cout << "Escuadrón creado. Total enemigos: " << Enemigo::totalEnemigos << endl;
				}
int main() {    
		crearEscuadron();    
		crearEscuadron();    
		return 0;
		}
```
### Cambios realizados:
- Se agregó un destructor `~Enemigo()` que libera la memoria asignada para el arreglo `armas` utilizando `delete[]`. Esto soluciona el problema de la fuga de memoria.
- En el destructor, también se decrementa `totalEnemigos` para reflejar correctamente la cantidad de enemigos activos en el juego. Esto asegura que el conteo de enemigos sea preciso y no cause confusión en la lógica del juego.  

Parte 3: reflexión metacognitiva
1. De todos los conceptos que exploraste en esta unidad (stack vs heap, paso de parámetros, ciclo de vida de objetos, etc.), ¿Cuál consideras que es el más crítico para evitar errores en programas reales? ¿Por qué?

Considero que la gestión de memoria, especialmente la comprensión de la diferencia entre el stack y el heap, es el concepto más crítico para evitar errores en programas reales. Esto se debe a que una mala gestión de memoria puede llevar a problemas graves como fugas de memoria, corrupción de datos y crashes del programa. Entender dónde se almacenan las variables y cómo se manejan los recursos es fundamental para escribir código eficiente y seguro, especialmente en lenguajes como C++ donde el programador tiene control directo sobre la memoria. 

2. ¿Cómo cambió tu comprensión sobre lo que realmente es un “objeto” después de comparar C++ con C#? ¿Qué implicaciones prácticas tiene esta diferencia?

Comparar C++ con C# me hizo entender que un "objeto" en C++ es una instancia de una clase que puede contener tanto datos como funciones miembro, y que su gestión de memoria es más explícita y manual. En contraste, en C#, los objetos son gestionados por el recolector de basura, lo que simplifica la gestión de memoria pero también puede ocultar detalles importantes sobre cómo se almacenan y manejan los recursos. Esta diferencia tiene implicaciones prácticas en términos de rendimiento y control: en C++, el programador tiene más control sobre la memoria y puede optimizar el uso de recursos, pero también debe ser más cuidadoso para evitar errores; mientras que en C#, el programador puede centrarse más en la lógica del programa sin preocuparse tanto por la gestión de memoria, aunque esto puede llevar a problemas de rendimiento si no se maneja adecuadamente.

3. Si tuvieras que explicar a un compañero de semestres anteriores por      qué es importante entender la gestión de memoria en programación, ¿Qué le dirías en máximo 3 oraciones?

Entender la gestión de memoria es crucial porque una mala gestión puede causar fugas de memoria, corrupción de datos y fallos en el programa. En lenguajes como C++, el programador debe manejar manualmente la asignación y liberación de memoria, lo que requiere conocimiento profundo de cómo funciona el sistema subyacente. Esto permite escribir código más eficiente y evitar errores críticos que pueden ser difíciles de detectar en entornos más abstractos como C#.