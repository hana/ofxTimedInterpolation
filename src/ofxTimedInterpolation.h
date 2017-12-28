//
//  ofxTimedInterpolation.h
//

#ifndef ofxTimedInterpolation_h
#define ofxTimedInterpolation_h

#include <stdio.h>
#include <chrono>

class ofxTimedInterpolation {
public:
    ofxTimedInterpolation();
    void bang();
    void bang(double _durationMsec);
    double getd();  //Returns value in double
    float get();    //Returns value in float
    void getReady();
    void setDuration(double _durationMsec);
    bool isWaiting;
    
private:

    double value;
    double duration;
    std::chrono::system_clock::time_point start;
    
};

#endif /* ofxTimedInterpolation_h */
