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
    void overBang();
    void setTime(int &time);
		
    
    //Interpolation
    ofxTimedInterpolation timedInterpolation;
    float value;
    bool isWaiting;
    
    
    //Gui
    ofxPanel gui;
    ofxIntSlider time;
    ofxButton bangButton;
    ofxButton overBangBtn;
};
