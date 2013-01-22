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
	centerImage.loadImage("Home_Center.png");
	centerImage.setAnchorPercent(0.5, 0.5);
	ofSetFrameRate(30);
	
	growUp = 0.5;
	touchk = 3;
	ss = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	
	if (touchk == 1) {
		for (count = 0; count < 100; count++) {
			reafs.push_back(new GReaf(count*137.5,-100,0,0,0,
									  ofRandom(-400,-205),ofRandom(-20,20),0,ofRandom(-120,120),
									  growUp*ofRandom(1,30),growUp*ofRandom(1,15),growUp*ofRandom(1,20),growUp*ofRandom(1,20),1));
		}
		
		touchk = 3;
			//各草を縮ませる命令を出す　その後、徐々に草のメモリを解放していく
	}else if (touchk == 0 && reafs.size()>0) {
		for (int i = 0; i < reafs.size(); i++) {
			reafs[i]->rTouch = 0;
		}
		touchk = 4;
	}
		//消し終わった後にtouchkが３に戻らなかった場合３にする
	if (touchk == 0 && reafs.size() == 0) {
		touchk = 3;
	}
	
	for (int i = 0; i < reafs.size(); i++) {
		reafs[i]->update();
	}
	
	
	if (touchk == 4) {
		/*
		 int s = ofGetSeconds();
		 if (s > ss || s < ss && timer < 10) {
		 timer++;
		 }
		 ss = s;
		 */
		
		if (reafs.size()>0) {
			delete reafs[reafs.size()-1];
			reafs.pop_back();
		}
		if (reafs.size()== 0) {
			touchk = 3;
		}
	}
	/*
	 if (timer >= 10) {
	 for (int i = 0; i < reafs.size(); i++) {
	 delete reafs[reafs.size()-1];
	 reafs.pop_back();
	 }
	 timer = 0;
	 touch = 3;
	 }*/
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255,0,0);
	ofCircle(0, 0, 20);
	ofCircle(768, 1024, 20);
	ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 30, 10);
	ofDrawBitmapString("touch: "+ofToString(touchk), 30, 25);
	glPushMatrix();
	ofTranslate(mouseX, mouseY, 0);
	for (int i = 0; i < reafs.size(); i++) {
		reafs[i]->draw();
	}
	ofSetColor(255, 255, 255, 255);
	ofFill();
	ofEllipse(0, 0, 210, 210);
	ofSetColor(255, 255, 255, reafs.size()*2);
	/*
	 if (reafs.size()>0) {
	 centerImage.draw(0, 0, 280, 280);
	 }*/
	centerImage.draw(0,0, 295,295);
	glPopMatrix();	
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
	if (touchk == 3) {
		touchk = 1;
		
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

