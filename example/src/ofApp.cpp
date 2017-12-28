#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);
    
    
    //Gui
    gui.setup();
    gui.add(startButton.setup("start"));
    startButton.addListener(this, &ofApp::start);
    gui.add(time.setup("time", 1000, 0, 4000));
    
    
    //Set duration
    timedInterpolation.setDuration(time);
    
    ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    ratio = timedInterpolation.get();
    isWaiting = timedInterpolation.isWaiting;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Get current ratio
    string text = "Current ratio : " + ofToString(ratio);
    ofDrawBitmapString(text, 10, 100);
    
    //Get if its already reached the time
    if(isWaiting) {
        text = "Timer is waiting.";
    } else {
        text = "Timer is working.";
    }
    ofDrawBitmapString(text, 10, 120);
    
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    timedInterpolation.setDuration(time);
    timedInterpolation.bang();
}

//--------------------------------------------------------------
void ofApp::start() {
    timedInterpolation.bang(time);  //Start with duration
}
