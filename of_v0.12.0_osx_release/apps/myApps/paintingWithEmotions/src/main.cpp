#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
    // Set up the OpenGL context and create the window
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    
    // This kicks off the running of my app
    ofRunApp(new ofApp());
}

