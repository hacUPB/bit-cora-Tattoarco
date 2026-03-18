## Actividad 1 

### Saberes previos
1. ¿Qué es el encapsulamiento para ti? Describe una situación en la que te haya sido útil o donde hayas visto su importancia.

Consiste en hacer que no se pueda acceder a los datos de un objeto directamente, sino a través de métodos específicos.  

Me ha sido útil al crear el primer videojuego, ya que me permitió proteger los datos de los objetos del juego y evitar que se modificaran accidentalmente. Por ejemplo, al encapsular la información de un personaje, pude asegurarme de que su salud solo se modificara a través de métodos específicos, lo que evitó errores y mantuvo la integridad del juego.


2. ¿Qué es la herencia? ¿Por qué un programador decidiría usarla? Da un ejemplo simple.

La herencia es un prinicipio que permite crear una nueva clase y que esta herede atributos y métodos de una clase ya exixtente. Un programador decide utilizarls para reutilizar código y hacer que el programa de más fácil de mantener. 

3. ¿Qué es el polimorfismo? Describe con tus palabras qué significa que un código sea “polimórfico”.

Es la capacidad de un clase de responder a un llamado de una sub-clase de forma diferente al mismo método. Un código es plimorofo cuando se puede usar el mismo método para diferentes tipos de objetos, y cada objeto puede responder de manera diferente a ese método. 

## Parte 2: 
Al depurar el código dado en la cosolo se mostró la siguente salida 

![Actividad 1](img/image.png)

**Encapsulamiento:**

- Señala una línea de código que sea un ejemplo claro de encapsulamiento y explica por qué lo es.

```.c#
private string nombre;
public double Radio { get; private set;}
public double Base { get; private set;}
public double Altura { get; private set;}
```

Estas líneas de código estan encapsuladas porque son privadas y solo se pueden acceder a traves de métodos especificos en la misma clase, protegiendo los datos.


- ¿Por qué crees que el campo nombre es private pero la propiedad Nombre es public? ¿Qué problema se evita con esto?

Se vuelve privado el campo `nombre` se privatisa para evitar que este sea modificado desde otros lugares del código. En cambio la propiedad `Nombre` es publica para poder acceder a su valor desde otras partes del código, evitando así, que el valor de `nombre` sea modificado directamente, lo que podría causar errores o inconsistencias en el programa.

**Herencia:**

- ¿Cómo se evidencia la herencia en la clase Circulo?

En la línea: 

```c#
public class Circulo : Figura
```

Se evidencia la herencia en la clase Circulo porque se indica que Circulo es una subclase de Figura, lo que significa que Circulo hereda los atributos y métodos de Figura.

- Un objeto de tipo Circulo, además de Radio, ¿Qué otros datos almacena en su interior gracias a la herencia?

Gracias a la herencia un objeto de tipo Circulo también almacena el campo `nombre` y la propiedad `Nombre` que se encuentran en la clase Figura, ya que Circulo hereda estos miembros de Figura.

**Polimorfismo:**

- Observa el bucle `foreach`. La variable `fig` es de tipo Figura, pero a veces contiene un Circulo y otras un Rectangulo. Cuando se llama a `fig.Dibujar()`, el programa ejecuta la versión correcta. En tu opinión, ¿Cómo crees que funciona esto “por debajo”? No necesitas saber la respuesta correcta, solo quiero que intentes razonar cómo podría ser.

```.c#
foreach (Figura fig in misFiguras)
{
    fig.Dibujar();
}
```

`misFiguras` es una lista de figuras y cada figura tiene su propia implementacion del metodo dibujar. Esta figuras se almacenan en `fig` y al llamar a `fig.Dibujar()`, el programa determina en tiempo de ejecución qué versión del método Dibujar() debe ejecutar, dependiendo del tipo real del objeto que `fig` está referenciando en ese momento. Todo esto esta almacenado dentro del `heap.

## Parte 3:

1. Memoria y herencia: cuando creas un objeto Rectangulo, este tiene Base, Altura y también Nombre. ¿Cómo te imaginas que se organizan esos tres datos en la memoria del computador para formar un solo objeto? 


2. El mecanismo del polimorfismo: pensemos de nuevo en la llamada fig.Dibujar(). El compilador solo sabe que fig es una Figura. ¿Cómo decide el programa, mientras se está ejecutando, si debe llamar al Dibujar del Circulo o al del Rectangulo? Lanza algunas ideas o hipótesis.

3. La barrera del encapsulamiento: ¿Cómo crees que el compilador logra que no puedas acceder a un miembro private desde fuera de la clase? ¿Es algo que se revisa cuando escribes el código, o es una protección que existe mientras el programa se ejecuta? ¿Por qué piensas eso?