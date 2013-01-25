#pragma once
#ifndef _TESTAPP
#define _TESTAPP

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "GReaf.h"

class testApp : public ofxiPhoneApp {
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);
	void touchCancelled(ofTouchEventArgs &touch);

	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
	
	int rSwitch;
	float bef;
	ofPoint aft;
	float touchk;
	float growUp;
	int count;
	vector <GReaf *> reafs;
	
	ofImage centerImage;
    ofImage myImage;
    ofImage glImage;
    ofImage backImage;

};

#endif
