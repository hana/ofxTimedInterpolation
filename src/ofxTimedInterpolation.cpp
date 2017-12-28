//
//  timed_interpolation.cpp
//  t_agent
//
//  Created by Hana on 2017/12/12.
//
//

#include "ofxTimedInterpolation.h"

using namespace std::chrono;

ofxTimedInterpolation::ofxTimedInterpolation() {
    isWaiting = true;
    value = 0.0;
    duration = 1000.0;
}

void ofxTimedInterpolation::setDuration(double _durationMsec) {
    duration = _durationMsec;
    value = 0.0;
    isWaiting = true;
}

void ofxTimedInterpolation::bang() {
    if (isWaiting) {
        isWaiting = false;
        value = 0.0;
        start = system_clock::now();
    }
}

void ofxTimedInterpolation::getReady() {
    isWaiting = true;
    value = 0.0;
}

void ofxTimedInterpolation::bang(double _durationMsec) {
    if (isWaiting) {
        duration = _durationMsec;
        isWaiting = false;
        start = system_clock::now();
    }
}

double ofxTimedInterpolation::getd() {
    double result = 0.0;
    if (isWaiting) {
        result = value;
    } else {
        system_clock::time_point now = system_clock::now();
        
        double elapsed = duration_cast<milliseconds>(now-start).count();
        result = elapsed / duration;
        if (1.0 < result) {
            result = 1.0;
            value = result;
            isWaiting = true;
        }
    }
    
    return result;
}


float ofxTimedInterpolation::get() {
    float result = 0.0;
    if (isWaiting) {
        result = value;
    } else {
        system_clock::time_point now = system_clock::now();
        
        float elapsed = duration_cast<milliseconds>(now-start).count();
        result = elapsed / duration;
        if (1.0 < result) {
            result = 1.0;
            value = result;
            isWaiting = true;
        }
    }
    
    return result;
}
