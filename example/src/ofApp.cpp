#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);
    ofSetCircleResolution(60);


    //Gui
    gui.setup();
    gui.add(bangButton.setup("Bang"));
    bangButton.addListener(this, &ofApp::start);
    gui.add(time.setup("time", 1000, 0, 4000));
    time.addListener(this, &ofApp::setTime);
    gui.add(overBangBtn.setup("Force bang"));
    overBangBtn.addListener(this, &ofApp::overBang);

    //Set duration
    timedInterpolation.setDuration(time);

    ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    value = timedInterpolation.get();
    isWaiting = timedInterpolation.isWaiting;
}

//--------------------------------------------------------------
void ofApp::draw(){

    //Get current ratio
    ofSetColor(0);
    string text = "Current value : " + ofToString(value);
    ofDrawBitmapString(text, 10, 100);

    //Get if its already reached the time
    if(isWaiting) {
        text = "Timer is waiting.";
    } else {
        text = "Timer is working.";
    }

    ofDrawBitmapString(text, 10, 120);
    ofDrawBitmapString("FPS : " + ofToString(ofGetFrameRate()), 10, 140);

    //Circle to check
    if(value == 1.0) {
        ofSetColor(0, 255, 0);
    } else {
        ofSetColor(255, 0, 0);
    }
    ofDrawCircle(ofGetWidth() *0.5, ofGetHeight()*0.5 , 100);


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

void ofApp::setTime(int &time) {
    timedInterpolation.setDuration(time);
}

void ofApp::overBang() {
    timedInterpolation.overBang(time);  //Start with duration, restart timer
}
