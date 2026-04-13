## Actividad 2

1. **Identifica los Roles:**
   - ¿Qué clase actúa como la interfaz `Observer`? ¿Qué método define?

La clase que actúa como la interfaz `Observer` es la clase `Observer` misma, y define el método virtual puro `onNotify`, que debe ser implementado por cualquier clase que herede de `Observer`.

Y los métodos son `Observer ` y `onNotify`:

```c++
class Observer {
public:
	virtual ~Observer() = default;
	virtual void onNotify(const std::string& event) = 0;
};
```

    - ¿Qué clase actúa como `Subject`? ¿Qué métodos proporciona para gestionar observadores y notificar?

La clase que actua como `Subject` es la clase `Subject`, y proporciona los métodos `addObserver`, `removeObserver` para gestionar los observadores, y el método `notify` para enviar notificaciones a los observadores registrados.

```C++
class Subject {
public:
		void addObserver(Observer * observer);
		void removeObserver(Observer * observer);
protected:
		void notify(const std::string & event);
private:
		std::vector<Observer *> observers;
		};
```

    - ¿Qué clase es el `ConcreteSubject` en esta aplicación? ¿Por qué? (Pista: ¿Quién *envía* las notificaciones?)
    - ¿Qué clase(s) actúan como `ConcreteObserver`? ¿Por qué? (Pista: ¿Quién *recibe* y *reacciona* a las notificaciones?)

2. **Sigue el flujo de notificación:**
   - Localiza el método `keyPressed` en `ofApp.cpp`. ¿Qué sucede cuando se presiona la tecla ‘a’? ¿Qué método se llama?
   - Ve al método `notify` en la clase `Subject`. ¿Qué hace este método?
   - Localiza el método que implementa la interfaz `Observer` en la clase `Particle` (`onNotify`). ¿Qué hace este método cuando recibe el evento “attract”?

3. **Registro y eliminación de observadores:**
   - ¿En qué parte del código se añaden las instancias de `Particle` como observadores de `ofApp`? (Busca dónde se llama a `addObserver`).
   - Aunque no se usa explícitamente en este ejemplo simple, ¿Dónde se eliminarían los observadores si fuera necesario (por ejemplo, si una partícula se destruyera durante la ejecución)? (Busca `removeObserver`). ¿Por qué es importante el destructor de `ofApp` en este contexto?
