#pragma once

#include "ofMain.h"
#include "ofxTimedInterpolation.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void start();
		
    
    //Interpolation
    ofxTimedInterpolation timedInterpolation;
    float ratio;
    bool isWaiting;
    
    
    //Gui
    ofxPanel gui;
    ofxIntSlider time;
    ofxButton startButton;
};
