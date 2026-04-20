## Actividad 2

1. **Identifica los Roles:**

- ¿Qué clase actúa como la interfaz `Observer`? ¿Qué método define?

La clase que actúa como la interfaz `Observer` es la clase `Observer` misma, y define el método virtual `onNotify` y `~Observer()`, métodos que deben ser implementados por culaquie clase que herede de _Observer_

Y los métodos son `Observer ` y `onNotify`:

```c++
class Observer
public:
	//El ~ de observer indica que es un destructor
   virtual ~Observer() = default;
	  //const std::string& event = Indica que recibe un string por referencia constante llamado event
   virtual void onNotify(const std::string& event) = 0;
;
```

- ¿Qué clase actúa como `Subject`? ¿Qué métodos proporciona para gestionar observadores y notificar?

  La clase que actua como `Subject` es la clase `Subject`, y proporciona los métodos `addObserver`, `removeObserver` para gestionar los observadores, y el método `notify` para enviar notificaciones a los observadores registrados.

```C++
class Subject {
public:

// Funciónes que proporcionan un observador a la lista utilizando su dierección de memoria.
		void addObserver(Observer * observer);
		void removeObserver(Observer * observer);
protected:
		void notify(const std::string & event);
private:
		std::vector<Observer *> observers;
		};
```

- ¿Qué clase es el `ConcreteSubject` en esta aplicación? ¿Por qué? (Pista: ¿Quién *envía* las notificaciones?)

La clase `ofApp` actúa como el `ConcreteSubject` en esta aplicación, ya que es la clase que envía las notificaciones a los observadores registrados informandoles que su estado ha cambiado.

```C++
// Clase que hereda de ofBaseApp y Subject
class ofApp : public ofBaseApp, public Subject {
public:
// Indica que el ~ofApp es un destructor, que aunque esta sobreescribiendo sobre el método virtual.
	~ofApp() override;


	void setup() override;
	void update() override;
	void draw() override;
	void keyPressed(int key) override;
private:
	std::vector<Particle*> particles;
};
```

- ¿Qué clase(s) actúan como `ConcreteObserver`? ¿Por qué? (Pista: ¿Quién *recibe* y *reacciona* a las notificaciones?)

Las clases que actúan como `ConcreteObserver` son las instancias de la clase `Particle`, ya que estas reciben las notificaciones enviadas por `ofApp` y reaccionan a ellas implementando el método `onNotify`.

```C++
class Particle : public Observer {
public:
	Particle();
	// Es un destructor que sobre escribe
	~Particle() override;
	Particle(const Particle&) = delete;
	Particle& operator=(const Particle&) = delete;

   // Estas son las notificaciones  enviadas por el ofApp
	void update();
	void draw();
	void onNotify(const std::string& event) override;
	void setState(State* newState);
	ofVec2f position;
	ofVec2f velocity;
	float size;
	ofColor color;
private:
	void keepInsideWindow();
	State* state;
};
```

2. **Sigue el flujo de notificación:**

- Localiza el método `keyPressed` en `ofApp.cpp`. ¿Qué sucede cuando se presiona la tecla ‘a’? ¿Qué método se llama?

Al precionar la tecla `a` las partículas se atraen entre en la direccion de dónde se encuentre el mouse.

```c++
case 'a':
	notify("attract");
	break;
```

- Ve al método `notify` en la clase `Subject`. ¿Qué hace este método?

Este método reccore los observadores para enviar la notificación del cambio de de estado. Lo hace por medio de la búsqueda de su ubicación en la memoria pasandole el evento que se ejecua.

```c++

void Subject::notify(const std::string & event) {
		for (Observer * observer : observers) {
				observer->onNotify(event);
				}
		}

```

- Localiza el método que implementa la interfaz `Observer` en la clase `Particle` (`onNotify`). ¿Qué hace este método cuando recibe el evento “attract”?

Cuando el evento es "attact" se actualiza el estado y llama a la función `AttractState()`, lo que hace que las particulas se empiecen a atraer entre si en la dirección del mouse.

```c++
void Particle::onNotify(const std::string & event) {  
		if (event == "attract") {    
				setState(new AttractState());  
				} 
}
```

3. **Registro y eliminación de observadores:**

- ¿En qué parte del código se añaden las instancias de `Particle` como observadores de `ofApp`? (Busca dónde se llama a `addObserver`).

Se añaden después de enviar la la particula nueva, añadiendola a sí al observador.

```c++
for (int i = 0; i < 100; ++i) {    
			  Particle * p = ParticleFactory::createParticle("star");    
			  particles.push_back(p);    
			  addObserver(p);  
}
```

- Aunque no se usa explícitamente en este ejemplo simple, ¿Dónde se eliminarían los observadores si fuera necesario (por ejemplo, si una partícula se destruyera durante la ejecución)? (Busca `removeObserver`). ¿Por qué es importante el destructor de `ofApp` en este contexto?

Eliminaría los observadores en el destructor de `ofApp`, para asegurarse de que no haya referencias a objetos que ya han sido destruidos, lo cual podría causar errores o comportamientos inesperados.


