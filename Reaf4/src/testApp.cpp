#include "testApp.h"

	//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	centerImage.loadImage("Home_Center.png");
	centerImage.setAnchorPercent(0.5, 0.5);
	ofSetFrameRate(30);
	
	growUp = 0.5;
	touch = 3;
	ss = 0;
}

	//--------------------------------------------------------------
void testApp::update(){
	
	if (touch == 1) {
		for (count = 0; count < 200; count++) {
			reafs.push_back(new GReaf(count*137.5,-100,0,0,0,
										  ofRandom(-400,-205),ofRandom(-20,20),0,ofRandom(-120,120),
										  growUp*ofRandom(1,30),growUp*ofRandom(1,15),growUp*ofRandom(1,20),growUp*ofRandom(1,20),1));
		}
		
		touch = 3;
	}else if (touch == 0 && reafs.size()>0) {
			for (int i = 0; i < reafs.size(); i++) {
				reafs[i]->rTouch = 0;
			}
		touch = 4;
	}
	for (int i = 0; i < reafs.size(); i++) {
		reafs[i]->update();
	}
	
	
	if (touch == 4) {
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
			touch = 3;
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
	ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 10, 10);
	glPushMatrix();
	ofTranslate(mouseX, mouseY, 0);
	for (int i = 0; i < reafs.size(); i++) {
		reafs[i]->draw();
	}
	ofSetColor(255, 255, 255, 255);
	ofFill();
	ofEllipse(0, 0, 210, 210);
	ofSetColor(255, 255, 255, reafs.size());
	/*
	if (reafs.size()>0) {
		centerImage.draw(0, 0, 280, 280);
	}*/
	centerImage.draw(0,0, 295,295);
	glPopMatrix();
}

	//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

	//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

	//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

	//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

	//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	if (button == 0 && touch == 3) {
		/*for (int i = 0; i < reafs.size(); i++) {
			reafs[i]->rTouch = 0;
		}*/
		touch = 1;
	}
	if (button == 2) {
		touch = 0;
	}
}

	//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

	//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

	//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

	//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}