#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {    
		ofBackground(0);
		for (int i = 0; i < 20; i++) {
			strokes.enqueue(ofGetWidth()/ 2, ofGetHeight() / 2, 20, ofColor(250, 20), 2);
		}
}
//--------------------------------------------------------------
void ofApp::update() {    
		backgroundHue += 0.2;    
		if (backgroundHue > 255) 
				backgroundHue = 0;
    // TODO: agregar un nuevo trazo si el mouse está presionado.    
    // Usa strokes.enqueue(x, y, radius, color, opacity);

		if (ofGetMousePressed()) {
			strokes.enqueue(ofGetMouseX(), ofGetMouseY(), 20, ofColor(250, 20), 2);
		}
    }
//--------------------------------------------------------------
void ofApp::draw() {    
	ofColor color1 = ofColor::fromHsb(backgroundHue, 150, 240);
	ofColor color2 = ofColor::fromHsb(fmod(backgroundHue + 128, 255), 150, 240);
	ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
	if (strokes.front == nullptr)
		return;
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
	Node* current = strokes.front;
	int index = 0;
	while (current) {
		float hue = ofMap(index++, 0, strokes.size - 1, 0, 255);
		mesh.addColor(ofColor::fromHsb(hue, 200, 255));
		mesh.addVertex(glm::vec3(current->x, current ->y, 0.0f));
		current = current->next;
	}
	ofSetLineWidth(2);
	mesh.draw();


	// Círculos con tamaño y color variable    
	current = strokes.front;
	index = 0;
	ofNoFill();
	ofSetLineWidth(2);
	while (current) {
		float hue = ofMap(index, 0, strokes.size - 1, 0, 255);
		ofSetColor(ofColor::fromHsb(hue, 220, 255));
		float radius = ofMap(index++, 0, strokes.size - 1, 20, 5);
		ofDrawCircle(current->x, current->y, radius);
		current = current->next;
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {    
		if (key == 'c') {        
			strokes.clear();
				}    
		if (key == 'a') {


			// TODO: alternar entre 50 y 100 trazos.    
			if (strokes.size = 50) {
				for (int i = 0; i < 50; i++) {
					strokes.enqueue(ofGetWidth() / 2, ofGetHeight() / 2, 20, ofColor(250, 20), 2);
				}
			}
			else {
				for (int i = 0; i < 100; i++) {
					strokes.dequeue();
				}
			}

		}
		else if (key == 's') {        
				// TODO: guardar el frame actual.    
				}
		}

// Implementa aquí `enqueue()`
void BrushQueue::enqueue(float x, float y, float radius, ofColor color, float opacity) {
	Node* newNode = new Node(ofGetWidth() / 2, ofGetHeight() / 2, 20.0, (250, 20), 2);
	// TODO: crear un nuevo nodo y agregarlo al final de la cola.    
	// Si la cola supera `maxSize`, eliminar el nodo más antiguo con `dequeue()`
	if (front == nullptr) {
		front = rear = newNode;
	}
	else {
		front->next = newNode;
		front = newNode;
	}size++;

	if (size >= maxSize) {
		dequeue();
	}
}
// Implementa aquí `dequeue()`
void BrushQueue::dequeue() {
	// TODO: eliminar el nodo más antiguo si la cola no está vacía.

	if (front == nullptr)
		return;
	if (front == rear) {
		// Si solo hay un elemento            
		delete front;
		front = rear = nullptr;
	}
	else {
		Node* temp = front;
		front = temp->next;

		delete temp;
	}
	size--;
}

// Implementa aquí `clear()`
void BrushQueue::clear() {

	// TODO: eliminar todos los nodos de la cola.
	Node* current = front;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	front = rear = nullptr;
	size = 0;
}

// Implementa aquí `isEmpty()`
bool BrushQueue::isEmpty() {
	// TODO: retornar si la cola está vacía.
	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}
	
}