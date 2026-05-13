## Actividad 6

1. ¿Cuál es la diferencia entre un constructor y un destructor en C++?
    - Un constructor es una función especial que se llama automáticamente cuando se crea un objeto de una clase. Su propósito es inicializar los miembros del objeto. Un destructor, por otro lado, es una función especial que se llama automáticamente cuando un objeto es destruido o sale del alcance. Su propósito es liberar los recursos que el objeto pueda haber adquirido durante su vida útil, como memoria dinámica o archivos abiertos. En resumen, el constructor se encarga de la creación e inicialización del objeto, mientras que el destructor se encarga de la limpieza y liberación de recursos cuando el objeto ya no es necesario.

2. ¿Cuál es la diferencia entre un objeto y una clase en C++?
    - Una clase es una plantilla o un plano que define las propiedades (atributos) y comportamientos (métodos) de un tipo de dato. Es una abstracción que describe cómo se deben crear los objetos. Un objeto, por otro lado, es una instancia concreta de una clase. Es una entidad que tiene un estado (valores de sus atributos) y un comportamiento (métodos que puede ejecutar). En resumen, la clase es la definición o el diseño, mientras que el objeto es la realización o la instancia de esa definición. 

3. ¿Qué diferencia notas entre el objeto Punto en C++ y C#?
    - En C++, el objeto `Punto` es una instancia de la clase `Punto` que se puede crear tanto en la pila (stack) como en el montón (heap), dependiendo de cómo se declare. En C#, el objeto `Punto` es siempre una instancia de la clase `Punto` que se crea en el montón (heap) y se accede a través de una referencia. En C++, los objetos pueden ser creados directamente como variables locales, mientras que en C#, los objetos siempre se crean usando el operador `new`, lo que implica que son referencias a objetos en el heap. Además, en C++ se pueden usar punteros para manejar objetos, mientras que en C# se utilizan referencias, lo que simplifica la gestión de memoria y reduce el riesgo de errores como fugas de memoria o acceso a memoria no válida.

4. ¿Qué es `p` en C++ y qué es `p` en C#? (en uno de ellos `p` es un objeto y en el otro es una referencia a un objeto).
    - En C++, `p` es un objeto de la clase `Punto`. Tiene su propio espacio en memoria para almacenar sus atributos y métodos. En C#, `p` es una referencia a un objeto de la clase `Punto`. No es el objeto en sí, sino un puntero o referencia que apunta a la ubicación en memoria donde se encuentra el objeto. En C#, los objetos se crean en el heap y las variables como `p` contienen referencias a esos objetos, mientras que en C++, los objetos pueden ser creados tanto en el stack como en el heap, dependiendo de cómo se declaren.


5. ¿En qué parte de memoria se almacena `p` en C++ y en C#?
    - En C++, si `p` es declarado como una variable local dentro de una función, se almacenará en la pila (stack). Si `p` es declarado como un puntero y se asigna memoria dinámica usando `new`, entonces el objeto al que apunta `p` se almacenará en el montón (heap). En C#, las variables locales como `p` también se almacenan en la pila, pero el objeto al que `p` hace referencia se almacena en el montón (heap), ya que en C# todos los objetos se crean en el heap y las variables contienen referencias a esos objetos.

6. ¿Qué observaste con el depurador acerca de `p`? Según lo que observaste ¿Qué es un objeto en C++?

    - Al usar el depurador, se puede observar que `p` en C++ es un objeto que tiene sus propios atributos y métodos. Un objeto en C++ es una instancia de una clase que contiene datos (atributos) y funciones (métodos) que operan sobre esos datos. El objeto tiene su propio espacio en memoria para almacenar sus atributos, y puede interactuar con otros objetos a través de sus métodos. En resumen, un objeto en C++ es una entidad concreta que representa una instancia de una clase, con su propio estado y comportamiento.
