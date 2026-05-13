## Actividad 3

**Análisis del caso de estudio**

Revisa nuevamente el código, prestando atención a la clase `ParticleFactory` y su uso en `ofApp::setup`.


1. **Identifica la Factory:**

- ¿Qué clase actúa como la factory en este ejemplo?

La clase que actua como la factory es `createParticle`. 

- ¿Cuál es el “método factory” específico? ¿Es un método de instancia o estático?

El *Método factory* es un método creacional, que busca delegar los objetos y la lógica a subclases. Este es de `Estático`. 

- ¿Qué tipo de objeto devuelve este método fábrica?

El Factory Method devuelve objetos de un tipo común, generalmente definidos a través de una interfaz o una clase abstracta.

2. **Proceso de creación:**
- Observa el método `ParticleFactory::createParticle`. ¿Cómo decide qué tipo de partícula específica crear y configurar?

Depende de lo que se este llamando, si el método recibe un identificador es tipo `star` se genera un tamaño y color aleatorios: 

```c++
if (type == "star") {	
	particle->size = ofRandom(2.0f, 4.0f);
	particle->color = ofColor(255, 0, 0);
}
```

- ¿Qué información necesita el método fábrica para realizar su trabajo?

Necesita conocer un identificador, pasa saber que subclase instanciar, y un párameto de configuración, el cual es opcional, para entregar el objeto.

- ¿Qué devuelve si se le pasa un tipo desconocido? ¿Cómo podrías mejorar esto?

Duevuelve un puntero nulo, esto sucede porque lo solicitado no cumple con los `if` ya estipulados. Para mejorar esto, haría una clase estandar, que si lo solicidao no cumple con lo que ya esta estipulado devuelva un puntero general o por defecto. 


3. **Uso de Factory:**
- Localiza `ofApp::setup`. ¿Cómo se utiliza la `ParticleFactory` para poblar el vector `particles`?

Recorre bucles for dónde delega la creación de partículas, luego recibe un puntero y este lo guarda en particles.

- Compara esto con la alternativa: ¿Cómo se vería `ofApp::setup` si *no* usara la fábrica y tuviera que crear y configurar cada tipo de partícula (`star`, `shooting_star`, `planet`) directamente usando `new Particle()` y luego ajustando sus propiedades (`size`, `color`, `velocity`)?

Si no utilizara la fabrica se tendría que crear en el `setup()` cada caso de paticulas y toda su lógica dentro de este, haciendo la escalibilidad complicada.


## Bitácora 
1. Explica con tus propias palabras el propósito del patrón Factory Method (o Simple Factory, en este caso). ¿Qué problema principal aborda en la creación de objetos?

Este método ayuda a la creación de un código más organizado, que busca la delegación de tareas, evitando que se tengan que repetir múltiples veces. Haciendo que se puedan editar subclases evitando modificar grandes partes del código.

2. ¿Qué ventajas aporta el uso de ParticleFactory en ofApp::setup en comparación con instanciar y configurar las partículas directamente allí? Piensa en términos de organización del código (SRP - Single Responsibility Principle), legibilidad y facilidad para añadir nuevos tipos de partículas en el futuro.

Ayuda a la legibilidad del código, funciona para que este sea escalable y fácil de comprender.


3. Imagina que quieres añadir un nuevo tipo de partícula llamada "black_hole" que tiene tamaño grande, color negro y velocidad muy lenta. Describe los pasos que necesitarías seguir para implementar esto utilizando la ParticleFactory existente. ¿Tendrías que modificar ofApp::setup? ¿Por qué sí o por qué no?

En `ParticleFactory` creo un nuevo tipo de paticula dandole el tamaño y color deseados, para luego en el `ofAopp:setup` añadir un *for* que indique que debo hacer y como alamacenarlo en `particles`.

Lo tengo que implementar en `ofAopp:setup` ya que de esta forma doy las indicacionesde qué hacer con esta nuava paticula creada bajo las instrucciones dadas y me queda almacenada para ser utilizada.


4. El método createParticle en el ejemplo es estático. ¿Qué implicaciones (ventajas/desventajas) tiene esto comparado con tener una instancia de ParticleFactory y un método de instancia createParticle()?.



