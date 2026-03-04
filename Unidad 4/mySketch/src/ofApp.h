#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		// Funciones básicas eindispensables para el funcionaminto del código
		void setup();
		void update();
		void draw();

		// Eventos que se pueden ejecutar con acciones externas 
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
