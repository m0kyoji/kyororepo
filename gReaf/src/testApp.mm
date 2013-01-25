#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	// register touch events
	ofRegisterTouchEvents(this);
	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
	
	//If you want a landscape oreintation 
	//iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
	
	ofBackground(255,255,255);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	centerImage.loadImage("Home_center.png");
	centerImage.setAnchorPercent(0.5, 0.5);
    backImage.loadImage("paper.jpg");
	backImage.setAnchorPercent(0, 0);
    
	ofSetFrameRate(30);
    ofSetCircleResolution(64);
	
	growUp = 0.5;
	touchk = 3;
	rSwitch = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
	
	if (touchk == 1) {
		for (count = 0; count < 100; count++) {
			reafs.push_back(new GReaf(count*137.5,-100,0,0,0,
									  ofRandom(-400,-255),ofRandom(-20,20),0,ofRandom(-120,120),
									  growUp*ofRandom(1,30),growUp*ofRandom(1,15),growUp*ofRandom(1,20),growUp*ofRandom(1,20),1));
		}
		
		touchk = 3;

	}else if (touchk == 0 && reafs.size()>0) {//各草を縮ませる命令を出す　その後、徐々に草のメモリを解放していく
		for (int i = 0; i < reafs.size(); i++) {
			reafs[i]->rTouch = 0;
		}
		touchk = 4;
	}

	if (touchk == 0 && reafs.size() == 0) {//消し終わった後にtouchkが３に戻らなかった場合３にする

		touchk = 3;
	}
	
	for (int i = 0; i < reafs.size(); i++) {
		reafs[i]->update();
	}
	
	if (rSwitch == 1) {
		aft = ofPoint(mouseX,mouseY);
		for (int i = 0; i < reafs.size(); i++) {
			reafs[i]->spot = aft;
		}
	}
	
	if (touchk == 4) {
		
		if (reafs.size()>0) {
			delete reafs[reafs.size()-1];
			reafs.pop_back();
		}
		if (reafs.size()== 0) {
			touchk = 3;
			rSwitch = 0;
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255);
    backImage.draw(0,0, ofGetWidth(),ofGetHeight());

	ofSetColor(255,0,0);
	ofCircle(0, 0, 20);
	ofCircle(640, 960, 20);
	ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 30, 10);
	ofDrawBitmapString("touch: "+ofToString(touchk), 30, 25);    
	glPushMatrix();
	ofTranslate(mouseX, mouseY, 0);
	for (int i = 0; i < reafs.size(); i++) {
		reafs[i]->draw();
	}
	//ofSetColor(255, 255, 255, 255);
	ofFill();
	ofSetColor(255, 255, 255 ,reafs.size()*2.5);
    ofEllipse(0, 0, 240, 240);

	/*
	 if (reafs.size()>0) {
	 centerImage.draw(0, 0, 280, 280);
	 }*/
	centerImage.draw(0,0, 340,340);
	glPopMatrix();	
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
	if (touchk == 3) {
		touchk = 1;
		rSwitch = 1;
		
		ofSetColor(255, 0, 0);
		ofCircle(0, 0, 10);
	}
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){
	touchk = 0;
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}


//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs& args){

}

