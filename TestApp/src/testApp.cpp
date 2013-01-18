#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofBackground(255, 255, 255);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
    
    //四角形を描く
    ofSetColor(64, 180, 210, 100);
    ofRect(200, 200, 100, 300);
	
	//多角形
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	ofVertex(200, 500);
	ofVertex(300, 200);
	ofVertex(500, 500);
	ofVertex(300, 300);
	ofEndShape();
	
	ofBeginShape();
	ofVertex(200, 500);
	ofVertex(350, 200);
	ofVertex(500, 500);
	ofVertex(350, 300);
	ofEndShape();
	/*
	ofBeginShape();
	ofVertex(200, 500);
	ofVertex(400, 200);
	ofVertex(500, 500);
	ofVertex(400, 300);
	ofEndShape();
	 */
	/*
	ofSetColor(64, 180, 210,100);
	ofRect(100, 100, 647, 80);
	ofRect(100, 190, 647, 20);
	ofRect(100, 231, 647, 14);
	
	
	ofSetColor(200, 100, 100, 50);
	ofRect(100, 100, 647, 400);
	*/
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