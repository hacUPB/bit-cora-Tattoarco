#pragma once
#include "ofMain.h"
// Nodo de la cola
struct Node {

	float x, y;
	float radius;
	ofColor color;
	float opacity;
	Node* next;
	Node(float _x, float _y, float _radius, ofColor _color, float _opacity) : x(_x), y(_y), radius(_radius), color(_color), opacity(_opacity), next(nullptr) {}
};

struct listNode {

};

// Implementación manual de una cola (FIFO)
class BrushQueue {
public:
	Node* front;
	Node* rear;
	int size;
	int maxSize;
	BrushQueue(int _maxSize);
	~BrushQueue();
	void enqueue(float x, float y, float radius, ofColor color, float opacity);
	void dequeue();
	void clear();
	bool isEmpty();
};

// Constructor
BrushQueue::BrushQueue(int _maxSize) : front(nullptr), rear(nullptr), size(0), maxSize(_maxSize) {}
// Destructor
BrushQueue::~BrushQueue() {
	clear();
}



class ofApp : public ofBaseApp {
public:
	BrushQueue strokes; // Cola de trazos    
	float backgroundHue = 0;
	ofApp() : strokes(100) {} // Tamaño máximo de la cola
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
};