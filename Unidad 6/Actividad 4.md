## Actividad 4
**Análisis del caso de estudio**

Examina el código (`ofApp.h`, `ofApp.cpp`) enfocándote en las clases relacionadas con el estado (`State`, `NormalState`, `AttractState`, etc.) y cómo interactúan con `Particle`.

1. **Identifica los componentes:**
- ¿Cuál es la clase `Context`? ¿Qué miembro utiliza para mantener el estado actual?

La clase `Context` es la clase `Particle`, ya que esta almacena las instacias que luego se delegan a la *subclase*. Para mantener el estado actual utiliza **setState**, con el cual crea nuevos estados de una partícula.

- ¿Cuál es la interfaz `State`? ¿Qué métodos importantes define? (Piensa en `update`, `onEnter`, `onExit`).

La intefaz `Satate` es `State`, la cual define métodos importantes como lo son: update(), onEnter(), onExit(). 

```c++
class State {
public:
	virtual ~State() = default;
	virtual void update(Particle* particle) = 0;
	virtual void onEnter(Particle* particle) {}
	virtual void onExit(Particle* particle) {}
};
```


- Enumera las clases `ConcreteState`. ¿Qué comportamiento específico encapsula cada una?

 - NormalState: update() y onEnter()
 - AttractState: update()
 - RepelState:update()
 - StopState:update()


2. **Delegación del comportamiento:**
- Observa el método `Particle::update()`. ¿Cómo delega la lógica de actualización al estado actual?

Delega la lógica al llamar al asignar a `state` el comportamiento `Update()`, el cual ya trae lógica implementada.

- Compara el código dentro de `NormalState::update()`, `AttractState::update()`,
 `RepelState::update()` y `StopState::update()`. ¿Cómo encapsula cada clase un comportamiento diferente?

Particle al ya tener variables y métodos predefinidos, los cuales muchos ya vienen con espacios o comportamientos pedefinidos su funcionamiento es básico, solo llama a esto ya predefinido y le asigna nuevos valores y si necesita algo en especifico lo crea y le da una lógica.


3. **Transiciones de estado:**
- ¿Cómo cambia una `Particle` de un estado a otro? ¿Qué método es responsable de gestionar la transición? (Busca `setState`).

Al notificar el cambio de estado, el `onEnter` verifica si este nuevo estado cumple con lo necesario y el `onExit` elimina el estado anterior para evitar acumulacion de datos en la memoria. El método responsable de esto es el `onEnter()`

- ¿Qué sucede dentro de `Particle::setState()`? ¿Por qué son importantes los métodos `onEnter` y `onExit` de la interfaz `State` (aunque no todos los estados concretos los usen extensivamente en este ejemplo)? ¿Qué gestionan `onEnter` y `onExit` en `NormalState`?


- ¿Qué evento externo (mediado por el patrón Observer, que ya analizaste) desencadena la llamada a `setState` en una `Particle`? 

