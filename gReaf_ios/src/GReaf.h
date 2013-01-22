/*
 *  GReaf.h
 *  gReaf
 *
 *  Created by hrd_zemi on 13/01/22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _GREAF
#define _GREAF

#include "ofMain.h"

class GReaf {
public:
	GReaf(float rotZ,
		  float reafTopMov,float reafTopRLMov,float reafLeftMov,float reafRightMov,
		  float reafTopAft,float reafTopRLAft,float reafBottomAft,float reafLeftAft,
		  float reafTopSec,float reafTopRLSec,float reafLeftSec,float reafRightSec,
		  float rTouch);
	~GReaf();
	
	void setup();
	void draw();
	void update();
	
		//void setRotZ(float rotZ);
	
	float reafTopMov,reafTopRLMov,reafLeftMov,reafRightMov;
	float reafTopAft,reafTopRLAft,reafBottomAft,reafLeftAft;
	float reafTopSec,reafTopRLSec,reafLeftSec,reafRightSec;
	float reafRightAft;
	
	float rTouch;
private:
	
	float rotZ;
		//ofImage myImage;
		//ofImage glImage;
};

#endif