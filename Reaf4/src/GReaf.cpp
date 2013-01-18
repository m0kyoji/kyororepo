/*
 *  GReaf.cpp
 *  emptyExample
 *
 *  Created by hrd_zemi on 13/01/11.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "GReaf.h"

GReaf::GReaf(float _rotZ,float _reafTopMov,float _reafTopRLMov,float _reafLeftMov,float _reafRightMov,
			 float _reafTopAft,float _reafTopRLAft,float _reafBottomAft,float _reafLeftAft,
			 float _reafTopSec,float _reafTopRLSec,float _reafLeftSec,float _reafRightSec,
			 float _rTouch){
	
	rotZ = _rotZ;
	rTouch = _rTouch;
	
	reafTopMov = _reafTopMov;
	reafTopRLMov = _reafTopRLMov;
	reafLeftMov = _reafLeftMov;
		//reafLeftHeightMov = _reafLeftHeightMov;
	reafRightMov = _reafRightMov;
		//reafRightHeightMov = _reafRightHeightMov;
	
	reafTopAft = _reafTopAft;
	reafTopRLAft = _reafTopRLAft;
		//reafBottomAft = _reafBottomAft;
	reafLeftAft = _reafLeftAft;
		//reafLeftHeightAft = _reafLeftHeightAft;
		//reafRightAft =  _reafRightAft                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ;
		//reafRightHeightAft = _reafRightHeightAft;
	
	reafTopSec = _reafTopSec;
	reafTopRLSec = _reafTopRLSec;
	reafLeftSec = _reafLeftSec;
		//reafLeftHeightSec = _reafLeftHeightSec;
	reafRightSec = _reafRightSec;
		//reafRightHeightSec = _reafRightHeightSec;
	
	if (reafLeftAft < 0) {
		reafRightAft = ofRandom(reafLeftAft,0);
	}else {
		reafRightAft = ofRandom(0,reafLeftAft);
	}
	myImage.loadImage("shadow2_s.png");
	myImage.setAnchorPercent(0.5, 1);
	glImage.loadImage("gl.png");
	glImage.setAnchorPercent(0.5, 1);
	
}

GReaf::~GReaf(){
}

void GReaf::setup(){
}

void GReaf::update(){
		/////////////////////////////////
	if (rTouch == 1) {
		if (reafLeftAft < 0) {
			if (reafLeftAft < reafLeftMov) {
				reafLeftMov -= reafLeftSec;
			}
			if (reafRightAft < reafRightMov) {
				reafRightMov -= reafRightSec;
			}
		}
		
		if (0 < reafLeftAft) {
			if (reafLeftMov < reafLeftAft) {
				reafLeftMov += reafLeftSec;
			}
			if (reafRightMov < reafRightAft) {
				reafRightMov += reafRightSec;
			}
		}
			/////////////////////////////////
		if (reafTopMov > reafTopAft) {
			reafTopMov -= reafTopSec;
		}
	}
	if (rTouch == 0) {
		if (reafLeftAft < 0) {
			if (reafLeftMov < 0) {
				reafLeftMov += reafLeftSec;
			}
			if (reafRightMov < 0) {
				reafRightMov += reafRightSec;
			}
		}
		
		if (0 < reafLeftAft) {
			if (0 < reafLeftMov) {
				reafLeftMov -= reafLeftSec;
			}
			if (0 < reafRightMov) {
				reafRightMov -= reafRightSec;
			}
		}
			/////////////////////////////////
		if (reafTopMov < -100) {
			reafTopMov += reafTopSec;
		}
	}
}

void GReaf::draw(){
	ofRotateZ(rotZ);
	
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	
	glPushMatrix();
	ofSetColor(255, 255, 255);
	ofRotateZ(180);
	myImage.draw(0, 0, 100, reafTopMov);
	glImage.draw(0, 100, 50, reafTopMov+100);
	glPopMatrix();
		//
	ofSetColor(213, 255, 155, 235);
	ofFill();
	ofSetLineWidth(1);
				
	ofBeginShape();
	ofVertex(0, -100);
	ofBezierVertex(0, -100, reafLeftMov, -100, reafTopRLMov, reafTopMov);
	ofVertex(reafTopRLMov, reafTopMov);
	ofBezierVertex(reafTopRLMov, reafTopMov, reafRightMov, -100, 0, -100);
	ofEndShape();
		//
	ofSetColor(0, 123, 80, 170);
	ofNoFill();
	ofSetLineWidth(2);
	
	ofBeginShape();
	ofVertex(0, -100);
	ofBezierVertex(0, -100, reafLeftMov, -100, reafTopRLMov, reafTopMov);
	ofVertex(reafTopRLMov, reafTopMov);
	ofBezierVertex(reafTopRLMov, reafTopMov, reafRightMov, -100, 0, -100);
	ofEndShape();
		//ofNextContour();//
	ofBeginShape();
	ofVertex(0, -100);
	ofBezierVertex(0, -100, (reafLeftMov+reafRightMov)/2, -100, reafTopRLMov, reafTopMov);
	ofVertex(reafTopRLMov, reafTopMov);
	ofBezierVertex(reafTopRLMov, reafTopMov, (reafLeftMov+reafRightMov)/2, -100, 0, -100);
	ofEndShape();
	
}

	//void GReaf::setRotZ(float _rotZ){
	
	//rotZ = _rotZ;
	//}